// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PBLGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "Interfaces/PBLSaveActionInterface.h"
#include "Actors/PBLBaseCharacter.h"
#include "EngineUtils.h"

UPBLGameInstance::UPBLGameInstance()
{
	SaveGames = GetAllSaveGames();
	//creatureFactory = BigLaserCreatureFactory::GetInstance();
}

void UPBLGameInstance::SetIsNewGame()
{
	isNewGame = true;
}

bool UPBLGameInstance::GetIsNewGame() const
{
	return isNewGame;
}

void UPBLGameInstance::PlayerSpawned()
{
	if (isNewGame)
	{
		return;
	}
	SetPlayerData();
}

void UPBLGameInstance::CreateSaveSlot()
{
	SaveGameObject = Cast<UPBLSaveGame>(UGameplayStatics::CreateSaveGameObject(UPBLSaveGame::StaticClass()));
	SaveGames = GetAllSaveGames();
}

void UPBLGameInstance::GatherActorData()
{
	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AActor* Actor{ *It };
		if (!IsValid(Actor) || !Actor->Implements<UPBLSaveActionInterface>())
			continue;

		IPBLSaveActionInterface* Inter{ Cast<IPBLSaveActionInterface>(Actor) };
		if (Inter == nullptr)
			continue;

		FGuid SAI = Inter->Execute_GetActorSaveID(Actor);
		if (!SAI.IsValid())
		{
			continue;
		}
		FSaveActorData SAD = Inter->Execute_GetActorData(Actor);
		FMemoryWriter MemWriter(SAD.ByteData);
		FObjectAndNameAsStringProxyArchive Ar(MemWriter, true);
		Ar.ArIsSaveGame = true;
		Actor->Serialize(Ar);

		for (auto ActorComp : Actor->GetComponents())
		{
			if (!ActorComp->Implements<UPBLSaveActionInterface>())
				continue;

			IPBLSaveActionInterface* CompInter{ Cast<IPBLSaveActionInterface>(ActorComp) };
			if (CompInter == nullptr)
				continue;

			FSaveComponentData SCD = CompInter->Execute_GetComponentSaveData(ActorComp);
			FMemoryWriter CompMemWriter(SCD.ByteData);
			FObjectAndNameAsStringProxyArchive CAr(CompMemWriter, true);
			CAr.ArIsSaveGame = true;
			ActorComp->Serialize(CAr);
			SCD.ComponentClass = ActorComp->GetClass();
			SAD.ComponentData.Add(SCD);
		}

		SaveableActorData.Add(SAI, SAD);
	}

	GatherPlayerData();
}

void UPBLGameInstance::GatherPlayerData()
{
	auto playerCharacter{ UGameplayStatics::GetPlayerCharacter(GetWorld(), 0) };
	IPBLSaveActionInterface* Inter{ Cast<IPBLSaveActionInterface>(playerCharacter) };
	if (Inter == nullptr)
	{
		return;
	}

	auto SAD = Inter->Execute_GetActorData(playerCharacter);
	FMemoryWriter MemWriter(SAD.ByteData);
	FObjectAndNameAsStringProxyArchive Ar(MemWriter, true);
	Ar.ArIsSaveGame = true;
	playerCharacter->Serialize(Ar);
	for (auto ActorComp : playerCharacter->GetComponents())
	{
		if (!ActorComp->Implements<UPBLSaveActionInterface>())
			continue;

		IPBLSaveActionInterface* CompInter{ Cast<IPBLSaveActionInterface>(ActorComp) };
		if (CompInter == nullptr)
			continue;

		FSaveComponentData SCD = CompInter->Execute_GetComponentSaveData(ActorComp);
		FMemoryWriter CompMemWriter(SCD.ByteData);
		FObjectAndNameAsStringProxyArchive CAr(CompMemWriter, true);
		CAr.ArIsSaveGame = true;
		ActorComp->Serialize(CAr);
		SCD.ComponentClass = ActorComp->GetClass();
		SAD.ComponentData.Add(SCD);
	}
	PlayerData = SAD;
}

void UPBLGameInstance::SetPlayerData()
{
	auto playerCharacter{ UGameplayStatics::GetPlayerCharacter(GetWorld(), 0) };
	IPBLSaveActionInterface* Inter{ Cast<IPBLSaveActionInterface>(playerCharacter) };
	if (Inter == nullptr)
	{
		return;
	}

	playerCharacter->SetActorTransform(PlayerData.ActorTransform);
	FMemoryReader MemReader(PlayerData.ByteData);
	FObjectAndNameAsStringProxyArchive Ar(MemReader, true);
	Ar.ArIsSaveGame = true;
	playerCharacter->Serialize(Ar);

	for (auto ActorComp : playerCharacter->GetComponents())
	{
		if (!ActorComp->Implements<UPBLSaveActionInterface>())
			continue;

		IPBLSaveActionInterface* CompInter{ Cast<IPBLSaveActionInterface>(ActorComp) };
		if (CompInter == nullptr)
			continue;

		for (auto SCD : PlayerData.ComponentData)
		{
			if (SCD.ComponentClass != ActorComp->GetClass())
				continue;

			FMemoryReader CompMemReader(SCD.ByteData);
			FObjectAndNameAsStringProxyArchive CAr(CompMemReader, true);
			CAr.ArIsSaveGame = true;
			ActorComp->Serialize(CAr);
			if (SCD.RawData.IsEmpty())
			{
				break;
			}
			CompInter->Execute_SetComponentSaveData(ActorComp, SCD);
		}
	}

	Inter->Execute_UpdateFromSave(playerCharacter);
}

bool UPBLGameInstance::NoLevelLoaded()
{
	return CurrentlyLoadedLevel == "None";
}

void UPBLGameInstance::AddActorData(const FGuid& ActorID, FSaveActorData ActorData)
{
	SaveableActorData.Add(ActorID, ActorData);
}

FSaveActorData UPBLGameInstance::GetActorData(const FGuid& ActorID) const
{
	return SaveableActorData[ActorID];
}

void UPBLGameInstance::SaveGame()
{
	if (SaveGameObject == nullptr)
	{
		CreateSaveSlot();
	}
	GatherActorData();
	SaveGameObject->SetSaveActorData(SaveableActorData);
	SaveGameObject->SetPlayerData(PlayerData);
	//SaveGameObject->SetGameConfig(GameConfiguration);
	SaveGameObject->SetCurrentlyLoadedLevel(CurrentlyLoadedLevel);
	UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveGameName, 0);
}

void UPBLGameInstance::LoadGame()
{
	if (!UGameplayStatics::DoesSaveGameExist(SaveGameName, 0))
	{
		return;
	}
	//TODO: Add logging and error message about missing save game return;
	SaveableActorData.Empty();

	SaveGameObject = Cast<UPBLSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveGameName, 0));
	SaveableActorData = SaveGameObject->GetSaveActorData();
	PlayerData = SaveGameObject->GetPlayerData();
	FName currentlyLoadedLevel{ SaveGameObject->GetCurrentlyLoadedLevel() };
	//CurrentlyLoadedLevel = SaveGameObject->GetCurrentlyLoadedLevel();
	//GameConfiguration = SaveGameObject->GetGameConfig();
	LoadLevelAndGame(currentlyLoadedLevel);
}

void UPBLGameInstance::LoadLevelAndGame(const FName& LevelToLoad)
{
	FLatentActionInfo info;

	if (!NoLevelLoaded())
	{
		UGameplayStatics::GetStreamingLevel(this, CurrentlyLoadedLevel)->SetShouldBeLoaded(false);
		UGameplayStatics::UnloadStreamLevel(this, CurrentlyLoadedLevel, info, true);
		//UGameplayStatics::UnloadStreamLevel(this, CurrentlyLoadedLevel, {}, false);
	}

	auto loadLevel{ UGameplayStatics::GetStreamingLevel(this, LevelToLoad) };
	loadLevel->SetShouldBeLoaded(true);
	loadLevel->SetShouldBeVisible(true);

	info.CallbackTarget = this;
	info.Linkage = 0;
	info.UUID = __LINE__;
	info.ExecutionFunction = FName("LoadActorsOnLevel");
	UGameplayStatics::LoadStreamLevel(this, LevelToLoad, true, true, info);
}

void UPBLGameInstance::LoadActorsOnLevel()
{
	auto IsPie{ GetWorld()->WorldType == EWorldType::PIE };
	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (!IsValid(Actor) || !Actor->Implements<UPBLSaveActionInterface>())
		{
			continue;
		}
		IPBLSaveActionInterface* Inter{ Cast<IPBLSaveActionInterface>(Actor) };
		if (Inter == nullptr)
			continue;

		if (Inter->Execute_GetActorData(Actor).WasSpawned)
		{
			Actor->Destroy();
		}
		else if (IsPie)
		{
			Inter->Execute_ResetFromLoad(Actor);
		}
	}

	for (TTuple<FGuid, FSaveActorData> SAD : SaveableActorData)
	{
		if (SAD.Value.WasSpawned)
		{
			UClass* ToSpawnClass = SAD.Value.ActorClass;
			if (ToSpawnClass == APBLBaseCharacter::StaticClass() || ToSpawnClass->IsChildOf(APBLBaseCharacter::StaticClass()))
			{
				APBLBaseCharacter* SpawnedCharacter{ GetWorld()->SpawnActor<APBLBaseCharacter>(ToSpawnClass, SAD.Value.ActorTransform) };
				IPBLSaveActionInterface* Inter = Cast<IPBLSaveActionInterface>(SpawnedCharacter);
				if (Inter == nullptr)
				{
					SpawnedCharacter->Destroy();
					continue;
				}
				Inter->Execute_SetActorSaveID(SpawnedCharacter, SAD.Key);
				//SpawnedCharacter->SetWasSpawned(true);
				continue;
			}

			//ABigLaserBaseActor* SpawnedActor = GetWorld()->SpawnActor<ABigLaserBaseActor>(ToSpawnClass, SAD.Value.ActorTransform);
			//IPBLSaveActionInterface* Inter = Cast<IPBLSaveActionInterface>(SpawnedActor);
			//if (Inter == nullptr)
			//{
			//	SpawnedActor->Destroy();
			//	continue;
			//}
			//Inter->Execute_SetActorSaveID(SpawnedActor, SAD.Key);
			//SpawnedActor->SetWasSpawned(true);
		}
	}

	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (!IsValid(Actor) || !Actor->Implements<UPBLSaveActionInterface>())
		{
			continue;
		}
		IPBLSaveActionInterface* Inter{ Cast<IPBLSaveActionInterface>(Actor) };
		if (Inter == nullptr)
			continue;

		FGuid SAI = Inter->Execute_GetActorSaveID(Actor);
		if (!SaveableActorData.Find(SAI))
		{
			continue;
		}

		FSaveActorData SAD = SaveableActorData[SAI];
		Actor->SetActorTransform(SAD.ActorTransform);

		FMemoryReader MemReader(SAD.ByteData);
		FObjectAndNameAsStringProxyArchive Ar(MemReader, true);
		Ar.ArIsSaveGame = true;
		Actor->Serialize(Ar);
		Inter->Execute_UpdateFromSave(Actor);
		Inter->Execute_SetActorRawSaveData(Actor, SAD.RawData);

		for (auto ActorComp : Actor->GetComponents())
		{
			if (!ActorComp->Implements<UPBLSaveActionInterface>())
				continue;

			IPBLSaveActionInterface* CompInter{ Cast<IPBLSaveActionInterface>(ActorComp) };
			if (CompInter == nullptr)
				continue;

			for (auto SCD : SAD.ComponentData)
			{
				if (SCD.ComponentClass != ActorComp->GetClass())
					continue;

				FMemoryReader CompMemReader(SCD.ByteData);
				FObjectAndNameAsStringProxyArchive CAr(CompMemReader, true);
				CAr.ArIsSaveGame = true;
				ActorComp->Serialize(CAr);
				if (SCD.RawData.IsEmpty())
				{
					break;
				}
				CompInter->Execute_SetComponentSaveData(ActorComp, SCD);
			}
		}
	}
	SetPlayerData();
}

void UPBLGameInstance::LoadLevel(const FName& LevelToLoad)
{
	FLatentActionInfo info;

	if (!NoLevelLoaded())
	{
		UGameplayStatics::GetStreamingLevel(this, CurrentlyLoadedLevel)->SetShouldBeLoaded(false);
		UGameplayStatics::UnloadStreamLevel(GetWorld(), CurrentlyLoadedLevel, info, true);
	}

	auto loadLevel{ UGameplayStatics::GetStreamingLevel(this, LevelToLoad) };
	loadLevel->SetShouldBeLoaded(true);
	loadLevel->SetShouldBeVisible(true);
	UGameplayStatics::LoadStreamLevel(GetWorld(), LevelToLoad, true, true, info);
}

TArray<FString> UPBLGameInstance::GetAllSaveGames()
{
	//TArray<FString> Ret;
	//FString savePath = FPaths::ProjectSavedDir();
	//savePath += "SaveGames/*";
	//WIN32_FIND_DATA FindData;
	//HANDLE hFindData = ::FindFirstFile(*savePath, &FindData);
	//if (hFindData == INVALID_HANDLE_VALUE)
	//{
	//	return Ret;
	//}

	//while (::FindNextFile(hFindData, &FindData))
	//{
	//	if (FindData.cFileName[0] == '\0' ||
	//		FindData.cFileName[0] == '.' && FindData.cFileName[1] == '\0' ||
	//		FindData.cFileName[0] == '.' && FindData.cFileName[1] == '.' && FindData.cFileName[2] == '\0')
	//		continue;

	//	FString FileName(FindData.cFileName);
	//	if (FileName.EndsWith(".sav"))
	//	{
	//		Ret.Add(FileName.Mid(0, FileName.Len() - 4));
	//	}
	//}
	//::FindClose(hFindData);
	//return Ret;
	return TArray<FString>();
}

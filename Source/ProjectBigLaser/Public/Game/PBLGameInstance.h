// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PBLSaveGame.h"
#include "PBLGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBIGLASER_API UPBLGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	//class BigLaserCreatureFactory* creatureFactory;

	UPROPERTY()
	TMap<FGuid, FSaveActorData> SaveableActorData;
	UPROPERTY()
	class UPBLSaveGame* SaveGameObject{ nullptr };
	UPROPERTY()
	FString SaveGameName{ TEXT("Default") };
	UPROPERTY()
	FName CurrentlyLoadedLevel{ "None" };
	UPROPERTY()
	FSaveActorData PlayerData;
	UPROPERTY()
	TArray<FString> SaveGames;

	//FGameConfiguration GameConfiguration;

	bool isNewGame{ false };

	UPBLGameInstance();
	void CreateSaveSlot();
	void GatherActorData();
	void GatherPlayerData();
	void SetPlayerData();
	UFUNCTION(BlueprintCallable)
	bool NoLevelLoaded();

	//void DebugStartUp();
public:
	UFUNCTION(BlueprintCallable)
	void AddActorData(const FGuid& ActorID, FSaveActorData ActorData);
	UFUNCTION(BlueprintCallable)
	FSaveActorData GetActorData(const FGuid& ActorID) const;
	UFUNCTION()
	void SaveGame();
	UFUNCTION()
	void LoadGame();
	UFUNCTION()
	void LoadLevelAndGame(const FName& LevelToLoad);
	UFUNCTION()
	void LoadActorsOnLevel();
	UFUNCTION(BlueprintCallable)
	void LoadLevel(const FName& LevelToLoad);
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllSaveGames();
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetSaveGames() { return SaveGames; };
	UFUNCTION(BlueprintCallable)
	void SetSaveGameName(const FString& SaveGame) { SaveGameName = SaveGame; };
	UFUNCTION(BlueprintCallable)
	void SetCurrentLoadedLevel(const FName& LevelToLoad) { CurrentlyLoadedLevel = LevelToLoad; };

#pragma region Configuration
	//UFUNCTION(BlueprintCallable)
	//void SetGameConfig(const FGameConfiguration& config);
	//UFUNCTION(BlueprintCallable)
	//FGameConfiguration GetGameConfig() const;
	//UFUNCTION(BlueprintCallable)
	//void SetEnableHeadBob(const bool& bEnabled);
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//bool GetHeadBobEnabled() const;
	//UFUNCTION(BlueprintCallable)
	//void SetEnableZoomCamera(const bool& bEnabled);
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//bool GetEnableZoomCamera() const;
	//UFUNCTION(BlueprintCallable)
	//void SetDayLength(const EDayLength& Length);
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//EDayLength GetDayLength() const;

	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//void SetComplexNeedsEnabled(const bool& bEnabled);
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	//bool GetComplexNeedsEnabled() const;
#pragma endregion
	UFUNCTION(BlueprintCallable)
	void SetIsNewGame();
	UFUNCTION(BlueprintCallable)
	bool GetIsNewGame() const;
	UFUNCTION(BlueprintCallable)
	void PlayerSpawned();
	
};

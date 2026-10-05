// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PBLSaveGame.h"

void UPBLSaveGame::SetSaveActorData(TMap<FGuid, FSaveActorData> data)
{
	SavableActorData = data;
}

TMap<FGuid, FSaveActorData> UPBLSaveGame::GetSaveActorData() const
{
	return SavableActorData;
}

void UPBLSaveGame::SetCurrentlyLoadedLevel(const FName levelName)
{
}

FName UPBLSaveGame::GetCurrentlyLoadedLevel() const
{
	return CurrentlyLoadedLevel;
}

void UPBLSaveGame::SetPlayerData(const FSaveActorData data)
{
	PlayerData = data;
}

FSaveActorData UPBLSaveGame::GetPlayerData() const
{
	return PlayerData;
}

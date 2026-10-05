// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DataTypes/PBLSaveGameTypes.h"
#include "PBLSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBIGLASER_API UPBLSaveGame : public USaveGame
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TMap<FGuid, FSaveActorData> SavableActorData;
	UPROPERTY()
	FName CurrentlyLoadedLevel{ "None" };
	UPROPERTY()
	FSaveActorData PlayerData;
	//FGameConfiguration GameConfiguration;
public:
	void SetSaveActorData(TMap<FGuid, FSaveActorData> data);
	TMap<FGuid, FSaveActorData> GetSaveActorData() const;
	void SetCurrentlyLoadedLevel(const FName levelName);
	FName GetCurrentlyLoadedLevel() const;
	void SetPlayerData(const FSaveActorData data);
	FSaveActorData GetPlayerData() const;
	//void SetGameConfig(FGameConfiguration gameConfiguration);
	//FGameConfiguration GetGameConfig();
};

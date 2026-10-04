// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DataTypes/PBLSaveGameTypes.h"
#include "PBLSaveActionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPBLSaveActionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTBIGLASER_API IPBLSaveActionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	FGuid GetActorSaveID();
	virtual FGuid GetActorSaveID_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void SetActorSaveID(const FGuid& NewGuid);
	virtual void SetActorSaveID_Implementation(const FGuid& NewGuid);
	UFUNCTION(BlueprintNativeEvent)
	FSaveActorData GetActorData();
	virtual FSaveActorData GetActorData_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void SetComponentSaveData(FSaveComponentData Data);
	virtual void SetComponentSaveData_Implementation(FSaveComponentData Data);
	UFUNCTION(BlueprintNativeEvent)
	FSaveComponentData GetComponentSaveData();
	virtual FSaveComponentData GetComponentSaveData_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void UpdateFromSave();
	virtual void UpdateFromSave_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void SetActorRawSaveData(TArray<FString>& Data);
	virtual void SetActorRawSaveData_Implementation(TArray<FString>& Data);
	UFUNCTION(BlueprintNativeEvent)
	void ResetFromLoad();
	virtual void ResetFromLoad_Implementation();
};

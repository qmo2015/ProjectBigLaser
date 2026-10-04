// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/PBLSaveActionInterface.h"

// Add default functionality here for any IPBLSaveActionInterface functions that are not pure virtual.

FGuid IPBLSaveActionInterface::GetActorSaveID_Implementation()
{
	return FGuid();
}

void IPBLSaveActionInterface::SetActorSaveID_Implementation(const FGuid& NewGuid)
{
}

FSaveActorData IPBLSaveActionInterface::GetActorData_Implementation()
{
	return FSaveActorData();
}

void IPBLSaveActionInterface::UpdateFromSave_Implementation()
{
}

void IPBLSaveActionInterface::SetActorRawSaveData_Implementation(TArray<FString>& Data)
{
}

void IPBLSaveActionInterface::ResetFromLoad_Implementation()
{
}

void IPBLSaveActionInterface::SetComponentSaveData_Implementation(FSaveComponentData Data)
{
}

FSaveComponentData IPBLSaveActionInterface::GetComponentSaveData_Implementation()
{
	return FSaveComponentData();
}

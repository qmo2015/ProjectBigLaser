// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PBLMsgTypes.generated.h"

USTRUCT()
struct FPlayerDiedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PlayerId = -1;

	UPROPERTY()
	FVector Location = FVector::ZeroVector;
};
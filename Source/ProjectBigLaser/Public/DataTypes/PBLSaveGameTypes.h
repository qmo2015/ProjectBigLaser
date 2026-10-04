// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PBLSaveGameTypes.generated.h"

USTRUCT(BlueprintType)
struct FSaveComponentData
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<uint8> ByteData;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UClass* ComponentClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FString> RawData;
};

USTRUCT(BlueprintType)
struct FSaveActorData
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTransform ActorTransform;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<uint8> ByteData;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool WasSpawned = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UClass* ActorClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FSaveComponentData> ComponentData;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FString> RawData;

	FSaveActorData()
	{
	};

	FSaveActorData(const FTransform& ActorTrans, const bool& wasSpawned, UClass* actorClass)
		: ActorTransform(ActorTrans), WasSpawned(wasSpawned), ActorClass(actorClass)
	{
	};

	FSaveActorData(const FTransform& ActorTrans, const bool& wasSpawned, UClass* actorClass, TArray<FString> rawData)
		: ActorTransform(ActorTrans), WasSpawned(wasSpawned), ActorClass(actorClass), RawData(rawData)
	{
	};
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PBLPlayerComponentTypes.generated.h"

UENUM(BlueprintType)
enum class PBLPlayerStatType : uint8
{
	Health,
	Energy,
	Count
};

USTRUCT(BlueprintType)
struct FPBLCorePlayerStat
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	float max{ 100 };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	float current = { 100 };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	float currentTickRatePerSecond = { 1 };
public:
	FPBLCorePlayerStat() {};
	FPBLCorePlayerStat(float _max, float _current, float _tick);
	inline void TickStat(const float& DeltaTime)
	{
		current = FMath::Clamp(current + (currentTickRatePerSecond * DeltaTime), 0, max);
	}
	inline void Adjust(const float& Amount)
	{
		current = FMath::Clamp(current + Amount, 0, max);
	}
	inline void OverrideAdjust(const float& Amount)
	{
		current += Amount;
	}
	inline void AdjustTick(const float& newTick)
	{
		currentTickRatePerSecond = newTick;
	}
	inline float GetPercentile() const
	{
		return FMath::Clamp(current / max, 0.0, 1.0);
	}

	inline FString GetSaveString()
	{
		return FString::Format(TEXT("{0}|{1}|{2}"), { FString::SanitizeFloat(current), FString::SanitizeFloat(max), FString::SanitizeFloat(currentTickRatePerSecond) });
	}

	inline void UploadFromSave(TArray<FString> Parts)
	{
		if (Parts.Num() != 3)
		{
			return;
		}
		current = FCString::Atof(*Parts[0]);
		max = FCString::Atof(*Parts[1]);
		currentTickRatePerSecond = FCString::Atof(*Parts[2]);

	}

	friend FArchive& operator<<(FArchive& Ar, FPBLCorePlayerStat& Stat)
	{
		Ar << Stat.current;
		Ar << Stat.max;
		Ar << Stat.currentTickRatePerSecond;
		return Ar;
	}
};
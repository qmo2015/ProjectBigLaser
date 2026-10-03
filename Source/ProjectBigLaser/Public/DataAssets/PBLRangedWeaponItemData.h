// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/PBLBaseItemData.h"
#include "NiagaraSystem.h"
#include "PBLRangedWeaponItemData.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBIGLASER_API UPBLRangedWeaponItemData : public UPBLBaseItemData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> EquippedStaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<USkeletalMesh> EquippedSkeletalMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> EquippedStaticThirdPersonMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<USkeletalMesh> EquippedSkeletalThirdPersonMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float PrimaryActionRate{ 1.0 };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxRange{ 2000.f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float EffectiveWidth{ 5.f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float DamagePerInstance{ 5.f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector MuzzleOffset;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UNiagaraSystem> ParticleSystem;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> FirstPersonAnimInstanceClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> ThirdPersonAnimInstanceClass;
};

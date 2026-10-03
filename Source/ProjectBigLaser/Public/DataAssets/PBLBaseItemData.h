// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PBLBaseItemData.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class PBLItemType : uint8
{
	IT_RANGED_WEAPON,
	IT_MELEE_WEAPON,
	IT_EQUIPMENT,
	IT_CONSUMABLE,
	IT_JUNK,
	Count
};

UCLASS()
class PROJECTBIGLASER_API UPBLBaseItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FText ItemName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FText ItemDescription;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FText PickUpText;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FText UseText{ FText::FromString("Consume") };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Icon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	PBLItemType ItemType{ PBLItemType::IT_JUNK };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int MaxStackSize{ 1 };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> WorldMesh;
};

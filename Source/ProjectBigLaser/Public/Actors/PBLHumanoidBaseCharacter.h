// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PBLBaseCharacter.h"
#include "PBLHumanoidBaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBIGLASER_API APBLHumanoidBaseCharacter : public APBLBaseCharacter
{
	GENERATED_BODY()
protected:
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//TMap<ENEquipmentSlot, UBigLaserNItemData*> EquippedItems;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//class USkeletalMeshComponent* lefthandMesh;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//USkeletalMeshComponent* righthandMesh;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//USkeletalMeshComponent* armorMesh;
public:
	//void SetTrinketItem(UBigLaserNItemData* item);
	//void SetArmorItem(UBigLaserNItemData* item);
	//void SetLeftHandItem(UBigLaserNItemData* item);
	//void SetRightHandItem(UBigLaserNItemData* item);
	//void EquipItem(UBigLaserNItemData* item, EEquipmentSlot slotType = EEquipmentSlot::Count);
	//void EquipWeapon(class UWeaponItemBase* item = nullptr, bool righthandness = true, bool removeCurrent = true);
	//void EquipWeapon(TSubclassOf<UWeaponItemBase> item = nullptr, bool righthandness = true);

	//void EquipItem(ENEquipmentSlot slot, UBigLaserNItemData* itemToEquip);
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//ABigLaserEquippedCharItemBase* RightHandItem;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//ABigLaserEquippedCharItemBase* LeftHandItem;
	//bool EquipWeapon(ENEquipmentSlot slot, UBigLaserNItemData* weapon);
	//bool EquipClothing(ENEquipmentSlot slot, UBigLaserNItemData* clothing);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssets/PBLRangedWeaponItemData.h"
#include "PBLBeamWeapon.generated.h"

UCLASS()
class PROJECTBIGLASER_API APBLBeamWeapon : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Data", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPBLRangedWeaponItemData> itemData;

	bool bIsFiring{ false };
	FTimerHandle BeamTickTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> ThirdPersonWeaponMesh;

	class UNiagaraComponent* BeamComponent;

	UPROPERTY(EditAnywhere, Category = "Animation")
	TSubclassOf<UAnimInstance> FirstPersonAnimInstanceClass;
	/** AnimInstance class to set for the third person character mesh when this weapon is active */
	UPROPERTY(EditAnywhere, Category = "Animation")
	TSubclassOf<UAnimInstance> ThirdPersonAnimInstanceClass;

private:
	TTuple<FVector, FVector> GetBeamPos();

protected:
	virtual void BeginPlay() override;
	void BeamTick();

public:	
	APBLBeamWeapon();
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void PrimaryActionStart();
	UFUNCTION(BlueprintCallable)
	void PrimaryActionEnd();
	UFUNCTION(BlueprintCallable)
	inline const TSubclassOf<UAnimInstance>& GetFirstPersonAnimInstanceClass() const
	{
		return FirstPersonAnimInstanceClass;
	}
	UFUNCTION(BlueprintCallable)
	inline const TSubclassOf<UAnimInstance>& GetThirdPersonAnimInstanceClass() const
	{
		return ThirdPersonAnimInstanceClass;
	}
	UFUNCTION(BlueprintPure, Category = "Weapon")
	USkeletalMeshComponent* GetFirstPersonMesh() const { return WeaponMesh; };

	/** Returns the third person mesh */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	USkeletalMeshComponent* GetThirdPersonMesh() const { return ThirdPersonWeaponMesh; };
};

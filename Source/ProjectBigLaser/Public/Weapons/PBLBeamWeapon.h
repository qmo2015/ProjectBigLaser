// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PBLBeamWeapon.generated.h"

UCLASS()
class PROJECTBIGLASER_API APBLBeamWeapon : public AActor
{
	GENERATED_BODY()
	
private:	
	//TODO: item definition
	float bMaxRange{ 100.f };
	float bEffectWidth{ 5.f };
	float bPrimartActionTickRate{ 0.2f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector MuzzleOffset;

	bool bIsFiring{ false };
	FTimerHandle BeamTickTimer;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMesh> WeaponMeshAsset;

	class UNiagaraComponent* BeamComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))

	class UNiagaraSystem* BeamSystem;

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
};

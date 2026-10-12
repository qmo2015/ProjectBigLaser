// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DataTypes/PBLPlayerComponentTypes.h"
#include "Interfaces/PBLSaveActionInterface.h"
#include "PBLPlayerStatsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTBIGLASER_API UPBLPlayerStatsComponent : public UActorComponent, public IPBLSaveActionInterface
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	FPBLCorePlayerStat health{ FPBLCorePlayerStat(100, 100, 0) };
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	FPBLCorePlayerStat energy{ FPBLCorePlayerStat(100, 100, 1) };
	//class UCharacterMovementComponent* OwningCharMovementComp;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statline | Temperature", meta = (AllowPrivateAccess = "true"))
	//bool bConcernedAboutTemperature{ true };
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statline | Temperature", meta = (AllowPrivateAccess = "true"))
	//float CurrentBodyTemperature = 98.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statline | Protection", meta = (AllowPrivateAccess = "true"))
	float PiercingProtection{ 0.0f };
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statline | Protection", meta = (AllowPrivateAccess = "true"))
	//bool IsPlayerSleeping{ false };

	void UpdateBodyTemp(const float& DeltaTime);
	void TickEnergy(const float& deltaTime);
	void TickHealth(const float& deltaTime);
public:	
	// Sets default values for this component's properties
	UPBLPlayerStatsComponent();
	//TODO: HUD
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	void SetComponentSaveData_Implementation(FSaveComponentData Data) override;
	FSaveComponentData GetComponentSaveData_Implementation() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void TickStats(float DeltaTime);
	UFUNCTION(BlueprintCallable)
	float GetStatePercentage(const PBLPlayerStatType& statType) const;
	UFUNCTION(BlueprintCallable)
	float GetPiercingProtection() const;
	UFUNCTION(BlueprintCallable)
	void TakeDamage(const float& Amount);
	UFUNCTION(BlueprintCallable)
	void IsDead();
	void AdjustPiercingProtection(const float& Amount);
};

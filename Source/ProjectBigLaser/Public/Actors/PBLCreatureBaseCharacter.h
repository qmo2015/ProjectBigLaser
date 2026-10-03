// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PBLBaseCharacter.h"
#include "PBLCreatureBaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBIGLASER_API APBLCreatureBaseCharacter : public APBLBaseCharacter
{
	GENERATED_BODY()
//private:
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	ABigLaserBaseCharacter* BiteTargetActor;
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	class USphereComponent* BiteTrigger;
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	bool HasBiteAttack{ true };
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	float BiteAttackDamage{ 10 };
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	float AttackRange{ 150.f };
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	FVector BiteScale{ FVector(0.5) };
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	FVector BiteLocationOffset{ FVector(0) };
//	UFUNCTION()
//	void SetupMeleeCollision();
//protected:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//	UBehaviorTree* BehaviorTree;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//	int FleeThreadHold{ -1 };
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//	int AttackThreadHold{ 1 };
//	UFUNCTION(BlueprintCallable)
//	virtual float GetMeleeAttackRangeOffset() const;
//public:
//	ABigLaserNPCBase();
//	void OnMeleeBiteTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
//	void OnMeleeBiteTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
//	void OnConstruction(const FTransform& Transform) override;
//	UFUNCTION(BlueprintCallable)
//	UBehaviorTree* GetBehaviorTree() const;
//	int GetFleeThreadHold() const {
//		return FleeThreadHold;
//	}
//	int GetAttackThreadHold() const {
//		return AttackThreadHold;
//	}
//	void ApplyMeleeDamage() override;
//	void CharacterDeath() override;
//
//	UFUNCTION(BlueprintCallable)
//	float GetMeleeRange() const;
//	UFUNCTION(BlueprintCallable)
//	bool HasRangeWeapon() const;
};

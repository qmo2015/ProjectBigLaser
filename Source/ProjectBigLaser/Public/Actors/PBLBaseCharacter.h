// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PBLBaseCharacter.generated.h"

UCLASS()
class PROJECTBIGLASER_API APBLBaseCharacter : public ACharacter
{
	GENERATED_BODY()
private:
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//class UBigLaserNInventoryComponent* NewInventoryComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UAIPerceptionStimuliSourceComponent* StimuliSource;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	// Sets default values for this character's properties
	APBLBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
	//class UPlayerStatsComponent* StatComponent;

//#pragma region AnimState
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	EEquipAnimState PrevAnimState{ EEquipAnimState::EAS_UNARMED };
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//	EEquipAnimState NewAnimState{ EEquipAnimState::EAS_UNARMED };
//#pragma endregion
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UAIPerceptionStimuliSourceComponent* GetStimuliSource() const { return StimuliSource; };
};

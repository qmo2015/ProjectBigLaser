// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Stats/PBLPlayerStatsComponent.h"
#include "Common/PBLMacros.h"

// Sets default values for this component's properties
UPBLPlayerStatsComponent::UPBLPlayerStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPBLPlayerStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UPBLPlayerStatsComponent::SetComponentSaveData_Implementation(FSaveComponentData Data)
{
}

FSaveComponentData UPBLPlayerStatsComponent::GetComponentSaveData_Implementation()
{
	return FSaveComponentData();
}

// Called every frame
void UPBLPlayerStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TickStats(DeltaTime);
}

void UPBLPlayerStatsComponent::TickStats(float DeltaTime)
{
	TickEnergy(DeltaTime);
	TickHealth(DeltaTime);
}

float UPBLPlayerStatsComponent::GetStatePercentage(const PBLPlayerStatType& statType) const
{
	switch (statType)
	{
	case PBLPlayerStatType::Health:
		return health.GetPercentile();
	case PBLPlayerStatType::Energy:
		return energy.GetPercentile();
	default:
		break;
	}
	return 0.0f;
}

float UPBLPlayerStatsComponent::GetPiercingProtection() const
{
	return PiercingProtection;
}

void UPBLPlayerStatsComponent::TakeDamage(const float& Amount)
{
	health.Adjust(0 - abs(Amount));
}

void UPBLPlayerStatsComponent::IsDead()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.UnRegisterTickFunction();
}

void UPBLPlayerStatsComponent::AdjustPiercingProtection(const float& Amount)
{
	PiercingProtection = FMath::Clamp(PiercingProtection + Amount, 0, MAXPROTECTIONVALUE);
}

void UPBLPlayerStatsComponent::UpdateBodyTemp(const float& DeltaTime)
{
}

void UPBLPlayerStatsComponent::TickEnergy(const float& deltaTime)
{
	energy.TickStat(deltaTime);
}

void UPBLPlayerStatsComponent::TickHealth(const float& deltaTime)
{
	health.TickStat(deltaTime);
}

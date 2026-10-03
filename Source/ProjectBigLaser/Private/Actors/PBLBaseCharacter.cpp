// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/PBLBaseCharacter.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"

void APBLBaseCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (StimuliSource)
	{
		StimuliSource->UnregisterFromPerceptionSystem();
	}
	Super::EndPlay(EndPlayReason);
}

// Sets default values
APBLBaseCharacter::APBLBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//TODO: setup inventory component
}

// Called when the game starts or when spawned
void APBLBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APBLBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APBLBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


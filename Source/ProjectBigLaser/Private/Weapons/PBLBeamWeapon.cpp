// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/PBLBeamWeapon.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"


// Sets default values
APBLBeamWeapon::APBLBeamWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// create the first person mesh
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponMesh->SetCollisionProfileName(FName("NoCollision"));
	WeaponMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::FirstPerson);
	WeaponMesh->bOnlyOwnerSee = true;

	// create the third person mesh
	ThirdPersonWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Third Person Mesh"));
	ThirdPersonWeaponMesh->SetupAttachment(RootComponent);

	ThirdPersonWeaponMesh->SetCollisionProfileName(FName("NoCollision"));
	ThirdPersonWeaponMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::WorldSpaceRepresentation);
	ThirdPersonWeaponMesh->bOwnerNoSee = true;
}

TTuple<FVector, FVector> APBLBeamWeapon::GetBeamPos()
{
	FVector Start = WeaponMesh->GetSocketLocation(TEXT("Muzzle"));
	FVector Direction = WeaponMesh->GetSocketRotation(TEXT("Muzzle")).Vector();
	FVector End = Start + Direction * bMaxRange;

	FHitResult TraceHit;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(TraceHit, Start, End, ECC_Visibility, QueryParams))
	{
		End = TraceHit.ImpactPoint;
	}
	auto s = { Start, End };
	return { Start, End };
}

// Called when the game starts or when spawned
void APBLBeamWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APBLBeamWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Update beam visual
	if (bIsFiring && BeamComponent)
	{
		auto [start, end]{ GetBeamPos() };
		BeamComponent->SetVariablePosition(
			TEXT("User.BeamStart"),
			start
		);

		BeamComponent->SetVariablePosition(
			TEXT("User.BeamEnd"),
			end
		);
	}

}

void APBLBeamWeapon::BeamTick()
{
	if (!bIsFiring || !BeamComponent)
	{
		return;
	}
	// TODO: handle effect
}

void APBLBeamWeapon::PrimaryActionStart()
{
	bIsFiring = true;
	// set timer
	GetWorld()->GetTimerManager().SetTimer(BeamTickTimer, this, &APBLBeamWeapon::BeamTick, bPrimartActionTickRate, true);

	//spawn beam
	BeamComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(
		BeamSystem,
		WeaponMesh,
		TEXT("Muzzle"), 
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		EAttachLocation::SnapToTarget,
		false);

	if (BeamComponent)
	{
		auto [start, end] { GetBeamPos() };

		BeamComponent->SetVariablePosition(TEXT("User.BeamStart"), start);
		BeamComponent->SetVariablePosition(TEXT("User.BeamEnd"), end);
		BeamComponent->SetVariableFloat(TEXT("User.BeamWidth"), bEffectWidth);
	}
}

void APBLBeamWeapon::PrimaryActionEnd()
{
	bIsFiring = false;
	GetWorld()->GetTimerManager().ClearTimer(BeamTickTimer);
	// remove beam
	if (BeamComponent)
	{
		BeamComponent->DestroyComponent();
		BeamComponent = nullptr;
	}
}


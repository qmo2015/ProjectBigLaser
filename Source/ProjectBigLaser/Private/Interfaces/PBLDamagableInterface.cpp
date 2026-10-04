// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/PBLDamagableInterface.h"

// Add default functionality here for any IPBLDamagableInterface functions that are not pure virtual.

void IPBLDamagableInterface::ReceiveDamage_Implementation(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
}

void IPBLDamagableInterface::ReceiveDamageAmount_Implementation(const float DamageAmount)
{
}

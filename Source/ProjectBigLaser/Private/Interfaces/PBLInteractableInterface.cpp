// Fill out your copyright notice in the Description page of Project Settings.


#include "Interfaces/PBLInteractableInterface.h"

// Add default functionality here for any IPBLInteractableInterface functions that are not pure virtual.

FText IPBLInteractableInterface::GetInteractText_Implementation()
{
	return FText();
}

void IPBLInteractableInterface::Interact_Implementation(APBLBaseCharacter* Caller)
{
}

bool IPBLInteractableInterface::IsInteratable_Implementation() const
{
	return false;
}

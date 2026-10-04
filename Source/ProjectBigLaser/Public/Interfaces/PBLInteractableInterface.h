// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Actors/PBLBaseCharacter.h"
#include "PBLInteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPBLInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTBIGLASER_API IPBLInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	FText GetInteractText();
	virtual FText GetInteractText_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void Interact(class APBLBaseCharacter* Caller);
	virtual void Interact_Implementation(class APBLBaseCharacter* Caller);
	UFUNCTION(BlueprintNativeEvent)
	bool IsInteratable() const;
	virtual bool IsInteratable_Implementation() const;
};

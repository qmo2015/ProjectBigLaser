// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PBLDestroyableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPBLDestroyableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTBIGLASER_API IPBLDestroyableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void DestroyNoHP();
	virtual void DestroyNoHP_Implementation();
};

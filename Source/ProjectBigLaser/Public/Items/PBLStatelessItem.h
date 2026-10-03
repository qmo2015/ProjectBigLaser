// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssets/PBLBaseItemData.h"
#include "PBLStatelessItem.generated.h"

UCLASS()
class PROJECTBIGLASER_API APBLStatelessItem : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Data", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPBLBaseItemData> itemData;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> meshComponent;
public:	
	// Sets default values for this actor's properties
	APBLStatelessItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

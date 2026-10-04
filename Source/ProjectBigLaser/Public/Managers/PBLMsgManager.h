// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MessageEndpoint.h"
#include "DataTypes/PBLMsgTypes.h"
#include "PBLMsgManager.generated.h"

UCLASS()
class PROJECTBIGLASER_API APBLMsgManager : public AActor
{
	GENERATED_BODY()
private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> MessageEndpoint;
public:	
	// Sets default values for this actor's properties
	APBLMsgManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void HandlePlayerDied(
		const FPlayerDiedMessage& Message,
		const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
};

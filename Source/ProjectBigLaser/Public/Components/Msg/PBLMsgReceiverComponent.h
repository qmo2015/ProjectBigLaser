// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MessageEndpoint.h"
#include "DataTypes/PBLMsgTypes.h"
#include "PBLMsgReceiverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTBIGLASER_API UPBLMsgReceiverComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Endpoint;
public:	
	// Sets default values for this component's properties
	UPBLMsgReceiverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	template<typename MessageType>
	void AddMsg(TFunction<void(const MessageType&, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>&)> Handler);
		
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Msg/PBLMsgSenderComponent.h"
#include "MessageEndpointBuilder.h"

// Sets default values for this component's properties
UPBLMsgSenderComponent::UPBLMsgSenderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPBLMsgSenderComponent::BeginPlay()
{
	Super::BeginPlay();
	Endpoint = FMessageEndpoint::Builder((*FString::Printf(TEXT("MessageSender_%s"), *GetOwner()->GetName()))).Build();
}


// Called every frame
void UPBLMsgSenderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

template<typename MessageType>
void UPBLMsgSenderComponent::Send(const MessageType& Message)
{
	if (!Endpoint.IsValid())
	{
		return;
	}

	Endpoint->Publish(Message);
}
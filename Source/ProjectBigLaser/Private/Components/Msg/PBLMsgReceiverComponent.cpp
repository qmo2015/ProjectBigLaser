// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Msg/PBLMsgReceiverComponent.h"
#include "MessageEndpointBuilder.h"

// Sets default values for this component's properties
UPBLMsgReceiverComponent::UPBLMsgReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPBLMsgReceiverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPBLMsgReceiverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

template<typename MessageType>
void UPBLMsgReceiverComponent::AddMsg(TFunction<void(const MessageType&, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>&)> Handler)
{
	if (!Endpoint.IsValid())
	{
		Endpoint = FMessageEndpoint::Builder((*FString::Printf(TEXT("MessageReceiver_%s"), *GetOwner()->GetName())))
			.Build();
	}

	Endpoint->Subscribe<MessageType>(
		[Handler](const MessageType& Message,
			const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
		{
			Handler(Message, Context);
		});
}
//AddEndpoint<FMyMessage>(
//	[](const FMyMessage& Message,
//		const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
//	{
//		UE_LOG(LogTemp, Log, TEXT("Received message!"));
//	});
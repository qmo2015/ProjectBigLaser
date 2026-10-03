// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/PBLMsgManager.h"
#include "MessageEndpointBuilder.h"
// Sets default values
APBLMsgManager::APBLMsgManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APBLMsgManager::BeginPlay()
{
	Super::BeginPlay();
    MessageEndpoint =
        FMessageEndpoint::Builder(TEXT("PBLMsgManager"))
        .Handling<FPlayerDiedMessage>(
            this,
            &APBLMsgManager::HandlePlayerDied);
    //MessageEndpoint =
    //    FMessageEndpoint::Builder(TEXT("UIMessageManager"))
    //    .Handling<FHealthChangedMessage>(
    //        this,
    //        &UUIMessageManager::HandleHealthChanged)
    //    .Handling<FAmmoChangedMessage>(
    //        this,
    //        &UUIMessageManager::HandleAmmoChanged)
    //    .Handling<FObjectiveUpdatedMessage>(
    //        this,
    //        &UUIMessageManager::HandleObjectiveUpdated);
    if (MessageEndpoint.IsValid())
    {
        MessageEndpoint->Subscribe<FPlayerDiedMessage>();
    }
}

// Called every frame
void APBLMsgManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APBLMsgManager::HandlePlayerDied(const FPlayerDiedMessage& Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "PBLBTT_GetFleePoint.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBIGLASER_API UPBLBTT_GetFleePoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float FleeDistance{ 5000 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float RandomRadius{ 1000 };
public:
	UPBLBTT_GetFleePoint(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

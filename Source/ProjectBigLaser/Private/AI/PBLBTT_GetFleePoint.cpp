// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/PBLBTT_GetFleePoint.h"

UPBLBTT_GetFleePoint::UPBLBTT_GetFleePoint(const FObjectInitializer& ObjectInitializer)
{
	NodeName = "Get Fleet Point";
}

EBTNodeResult::Type UPBLBTT_GetFleePoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//if (ABigLaserAIControllerBase * Con{ Cast<ABigLaserAIControllerBase>(OwnerComp.GetAIOwner()) })
	//{
	//	if (APawn * npc{ Con->GetPawn() })
	//	{
	//		if (auto NavSys{ UNavigationSystemV1::GetCurrent(GetWorld()) })
	//		{
	//			auto FleePoint{ OwnerComp.GetBlackboardComponent()->GetValueAsVector(BBK_FLEEPOINT) };
	//			auto FleeDir{ UKismetMathLibrary::FindLookAtRotation(npc->GetActorLocation(), FleePoint) };
	//			FleeDir.Yaw += 180;
	//			npc->SetActorRotation(FRotator(0, FleeDir.Yaw, 0));
	//			auto SearchLoc{ npc->GetActorForwardVector() * FleeDistance + npc->GetActorLocation() };
	//			FNavLocation NewLoc;
	//			if (NavSys->GetRandomReachablePointInRadius(SearchLoc, RandomRadius, NewLoc))
	//			{
	//				Con->SetSprinting(true);
	//				OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), NewLoc.Location);
	//				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	//				return EBTNodeResult::Succeeded;
	//			}
	//			int i = 0;
	//			double newYaw;

	//			while (i < 23)
	//			{
	//				newYaw = FleeDir.Yaw;
	//				//even
	//				if (i % 2 == 0)
	//				{
	//					newYaw += ((i / 2) * -15);
	//				}
	//				//odd 
	//				else
	//				{
	//					if (i > 13)
	//					{
	//						i++;
	//						continue;
	//					}
	//					newYaw += (i * 15);
	//				}

	//				npc->SetActorRotation(FRotator(0, newYaw, 0));
	//				SearchLoc = npc->GetActorForwardVector() * FleeDistance + npc->GetActorLocation();

	//				if (NavSys->GetRandomReachablePointInRadius(SearchLoc, RandomRadius, NewLoc))
	//				{
	//					Con->SetSprinting(true);
	//					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), NewLoc.Location);
	//					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	//					return EBTNodeResult::Succeeded;
	//				}
	//				i++;
	//			}
	//			FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	//			return EBTNodeResult::Failed;
	//		}
	//	}
	//}
	FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	return EBTNodeResult::Failed;
}

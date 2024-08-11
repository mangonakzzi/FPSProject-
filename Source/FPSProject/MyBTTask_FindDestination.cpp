// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_FindDestination.h"
#include "FPSAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_FindDestination::UMyBTTask_FindDestination()
{
	NodeName = TEXT("FindPatrolDestination");


}

EBTNodeResult::Type UMyBTTask_FindDestination::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    //Super::ExecuteTask(OwnerComp, NodeMemory);
    //
    //auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
    //if (CurrentPawn != nullptr)
    //{
    //    auto NaveSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
    //    if (NaveSystem != nullptr)
    //    {
    //        FNavLocation RandomLocation;
    //        if (NaveSystem->GetRandomReachablePointInRadius(CurrentPawn->GetActorLocation(), 500.f, RandomLocation))
    //        {
    //            OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("Destination")), RandomLocation);
    //
    //            return EBTNodeResult::Succeeded;
    //        }
    //
    //    }
    //}

	return EBTNodeResult::Type();
}			

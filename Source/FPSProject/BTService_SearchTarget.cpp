// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SearchTarget.h"
#include "FPSAIController.h"
#include "FPSCharacter.h"
#include "Engine/OverlapResult.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_SearchTarget::UBTService_SearchTarget()
{
	NodeName = TEXT("SearchTarget");
	Interval = 1.f;

}

void UBTService_SearchTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn != nullptr)
	{
		UWorld* World = CurrentPawn->GetWorld();
		if (World != nullptr)
		{
			FVector Center = CurrentPawn->GetActorLocation();
			float SearchDistance = 500.f;
			TArray<FOverlapResult> OverlapResults;
			FCollisionQueryParams QueryParams(NAME_Name, false, CurrentPawn);

			bool Result = World->OverlapMultiByChannel
			(
				OverlapResults,
				Center,
				FQuat::Identity,
				ECollisionChannel::ECC_GameTraceChannel1,
				FCollisionShape::MakeSphere(SearchDistance),
				QueryParams
			);

			if (Result)
			{
				for (auto& OverlapResult : OverlapResults)
				{
					AFPSCharacter* FPSCharacter = Cast<AFPSCharacter>(OverlapResult.GetActor());
					if (FPSCharacter)
					{
						DrawDebugSphere(World, Center, SearchDistance, 10, FColor::Green, false, 0.5f);
						OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName("Target"), FPSCharacter);
						return;
					}
				}


				DrawDebugSphere(World, Center, SearchDistance, 10, FColor::Red, false, 0.5f);
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName("Target"), nullptr);
			}
			else
			{

				DrawDebugSphere(World, Center, SearchDistance, 10, FColor::Red, false, 0.5f);
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName("Target"), nullptr);
			}

		}

	}

}

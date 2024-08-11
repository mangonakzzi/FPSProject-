// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"

AFPSAIController::AFPSAIController()
{
	//static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("/Script/AIModule.BehaviorTree'/Game/AI/BT_Enemy.BT_Enemy'"));
	//if (BT.Succeeded())
	//{
	//	UE_LOG(LogTemp, Log, TEXT("BehaviorTree Succeeded"));
	//	BehaviorTree = BT.Object;
	//}
	//
	//
	//static ConstructorHelpers::FObjectFinder<UBlackboardData> BB(TEXT("/Script/AIModule.BlackboardData'/Game/AI/BB_Enemy.BB_Enemy'"));
	//if (BB.Succeeded())
	//{
	//	UE_LOG(LogTemp, Log, TEXT("BlackboardData Succeeded"));
	//	BlackboardData = BB.Object;
	//}

}

void AFPSAIController::OnPossess(APawn* InPawn)
{
	//Super::OnPossess(InPawn);
	//if (RunBehaviorTree(BehaviorTree))
	//{
	//	UE_LOG(LogTemp, Log, TEXT("Run Hehavior Tree"));
	//}

}

void AFPSAIController::OnUnPossess()
{
	//Super::OnUnPossess();

}

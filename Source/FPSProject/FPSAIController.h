// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FPSAIController.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API AFPSAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AFPSAIController();
private:
	UPROPERTY()
	class UBehaviorTree* BehaviorTree;
	UPROPERTY()
	class UBlackboardData* BlackboardData;
public:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

};

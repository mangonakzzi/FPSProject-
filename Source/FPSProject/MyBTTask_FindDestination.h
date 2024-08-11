// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTask_FindDestination.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API UMyBTTask_FindDestination : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UMyBTTask_FindDestination();

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};


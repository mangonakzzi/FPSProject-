// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSEnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API UFPSEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UFPSEnemyAnimInstance();

public:
	UPROPERTY(Category = "Animaiton", VisibleAnywhere, BlueprintReadOnly)
	class UCharacterMovementComponent* CharacterMovement;
	UPROPERTY(Category = "Animaiton", VisibleAnywhere, BlueprintReadOnly)
	bool ShouldMove = false;
	UPROPERTY(Category = "Animaiton", EditAnywhere, BlueprintReadOnly)
	UAnimMontage* AttackMontage;

public:
	void FireMontage();

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

};

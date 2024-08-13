// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSEnemyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UFPSEnemyAnimInstance::UFPSEnemyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("/Script/Engine.AnimMontage'/Game/ParagonMurdock/Characters/Heroes/Murdock/Animations/Fire_Fast_Montage.Fire_Fast_Montage'"));

	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}

}

void UFPSEnemyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();

	if (IsValid(Pawn))
	{
		auto Character = Cast<ACharacter>(Pawn);
		if (IsValid(Character))
		{
			CharacterMovement = Character->GetCharacterMovement();
		}

	}

}

void UFPSEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(CharacterMovement))
	{
		FVector Velocity = CharacterMovement->Velocity;
		float Speed = Velocity.Size2D();
		ShouldMove = Speed > 3.f;
	}

}

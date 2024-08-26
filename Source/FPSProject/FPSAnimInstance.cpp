// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h" 

#include "FPSCharacter.h"

UFPSAnimInstance::UFPSAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AnimMontage(TEXT("/Script/Engine.AnimMontage'/Game/ParagonRevenant/Characters/Heroes/Revenant/Animations/Primary_Fire_Med_Montage.Primary_Fire_Med_Montage'"));
	if (AnimMontage.Succeeded())
	{
		FireMontage = AnimMontage.Object;
	}

}

void UFPSAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	auto Pawn = TryGetPawnOwner();

	if (IsValid(Pawn))
	{
		FPSCharacter = Cast<AFPSCharacter>(Pawn);
		if (IsValid(FPSCharacter))
		{
			CharacterMovement = FPSCharacter->GetCharacterMovement();

		}

	}
}

void UFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(FPSCharacter))
	{
		Velocity = CharacterMovement->Velocity;
		FRotator Rotation = FPSCharacter->GetActorRotation();
		Speed = Velocity.Size2D();

		auto Acceleration = CharacterMovement->GetCurrentAcceleration();
		ShouldMove = Speed > 3.f && Acceleration != FVector::Zero();
		IsFalling = CharacterMovement->IsFalling();

		AimRotation = FPSCharacter->GetBaseAimRotation();
		FRotator VelocityRotation = UKismetMathLibrary::MakeRotFromX(Velocity);

		FRotator DeltaRotation = VelocityRotation - AimRotation;
		DeltaRotation.Normalize();

		YawOffset = DeltaRotation.Yaw;

	}

}

void UFPSAnimInstance::PlayFireMontage()
{
	//if (IsValid(FireMontage))
	//{
	//	if (!Montage_IsPlaying(FireMontage))
	//	{
	//		Montage_Play(FireMontage);
	//
	//	}
	//}

}

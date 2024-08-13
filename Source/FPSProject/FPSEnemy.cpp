// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSEnemy.h"
#include "Components/CapsuleComponent.h"
#include "FPSAIController.h"

// Sets default values
AFPSEnemy::AFPSEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/AIModule.BehaviorTree'/Game/Enemy/AI/BT_Enemy.BT_Enemy'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));

	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AI(TEXT("/Script/Engine.AnimBlueprint'/Game/Enemy/ABP_Enemy.ABP_Enemy_C'"));
	if (AI.Succeeded())
	{
		GetMesh()->SetAnimClass(AI.Class);

	}

	AIControllerClass = AFPSAIController::StaticClass();

}

// Called when the game starts or when spawned
void AFPSEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


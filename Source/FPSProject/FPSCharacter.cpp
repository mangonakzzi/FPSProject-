// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

#include "FPSAnimInstance.h"
#include "Projectile.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant.Revenant'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));

	}


	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("/Script/Engine.AnimBlueprint'/Game/Animation/ABP_Character.ABP_Character_C'"));
	if (AnimInstance.Succeeded())
	{
		GetMesh()->SetAnimClass(AnimInstance.Class);

	}
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto AnimInstance = GetMesh()->GetAnimInstance();
	FPSAnimInstance = Cast<UFPSAnimInstance>(AnimInstance);
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveUpDown"), this, &AFPSCharacter::KeyUpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &AFPSCharacter::KeyLeftRight);

	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &AFPSCharacter::MouseLookLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &AFPSCharacter::MouseLookUpDown);


	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AFPSCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AFPSCharacter::Fire);

}

void AFPSCharacter::KeyUpDown(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);

}

void AFPSCharacter::KeyLeftRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);

}

void AFPSCharacter::MouseLookLeftRight(float Value)
{
	AddControllerYawInput(Value);

}

void AFPSCharacter::MouseLookUpDown(float Value)
{
	AddControllerPitchInput(Value);

}

void AFPSCharacter::Fire()
{
	if (IsValid(FPSAnimInstance))
	{
		FPSAnimInstance->PlayFireMontage();
		FTransform SocketTransform = GetMesh()->GetSocketTransform(FName("gun_pin"));
		FVector SocketLocation = SocketTransform.GetLocation();
		FRotator SocketRotation = SocketTransform.GetRotation().Rotator();
		FActorSpawnParameters params;
		params.Owner = this;


		auto MyArrow = GetWorld()->SpawnActor<AProjectile>(SocketLocation, SocketRotation, params);

	}

}
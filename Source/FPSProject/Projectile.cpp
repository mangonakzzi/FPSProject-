// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"\

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Script/Engine.StaticMesh'/Game/ParagonRevenant/FX/Meshes/Shapes/SM_Burden_Projectile.SM_Burden_Projectile'"));

	if (StaticMesh.Succeeded())
	{
		//Mesh->SetStaticMesh(StaticMesh.Object);
		//Mesh->SetRelativeLocationAndRotation(FVector(0.f, 100.f, 0.f), FRotator(0.f, 90.f, 0.f));
		//Mesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	}

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collison Mesh"));
	CollisionMesh->SetupAttachment(Mesh);
	//CollisionMesh->SetRelativeLocation(FVector(12.f, 0.f, 0.f));
	//CollisionMesh->SetRelativeScale3D(FVector(0.45f, 0.45f, 0.45f));

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(DefaultRoot);
	ProjectileMovementComponent->InitialSpeed = 500.f;
	ProjectileMovementComponent->MaxSpeed = 500.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;

	
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


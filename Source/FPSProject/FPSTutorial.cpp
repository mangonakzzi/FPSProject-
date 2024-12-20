// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSTutorial.h"
#include "Components/BoxComponent.h"

// Sets default values
AFPSTutorial::AFPSTutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("/Script/Engine.StaticMesh'/Engine/EngineVolumetrics/LightBeam/Mesh/S_EV_SimpleLightBeam_02.S_EV_SimpleLightBeam_02'"));
	if (StaticMeshObject.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshObject.Object);

	}

	StaticMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(StaticMesh);

	StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
	BoxCollision->SetRelativeLocation(FVector(0.f, 0.f, -75.f));

}

// Called when the game starts or when spawned
void AFPSTutorial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSTutorial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


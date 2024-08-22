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

	//ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Script/Engine.Material'/Engine/EditorResources/FieldNodes/_Resources/M_FieldRadiusPreview.M_FieldRadiusPreview'"));
	//if (Material.Succeeded())
	//{
	//	StaticMesh->SetMaterialByName()
	//
	//}

	StaticMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(StaticMesh);

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


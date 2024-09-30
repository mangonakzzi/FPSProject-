// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameModeBase.h"
#include "FPSCharacter.h"

AFPSGameModeBase::AFPSGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AFPSCharacter> BP_FPSCharacter(TEXT("/Script/Engine.Blueprint'/Game/BluePrint/BP_Character.BP_Character_C'"));

	if (BP_FPSCharacter.Succeeded())
	{
		DefaultPawnClass = BP_FPSCharacter.Class;
	}
}

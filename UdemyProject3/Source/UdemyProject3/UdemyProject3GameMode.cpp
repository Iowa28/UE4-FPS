// Copyright Epic Games, Inc. All Rights Reserved.

#include "UdemyProject3GameMode.h"
#include "UdemyProject3HUD.h"
#include "UObject/ConstructorHelpers.h"

AUdemyProject3GameMode::AUdemyProject3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Character/Behaviour/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUdemyProject3HUD::StaticClass();
}

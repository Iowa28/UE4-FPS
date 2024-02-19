// Copyright Epic Games, Inc. All Rights Reserved.

#include "UdemyProject3GameMode.h"
#include "UdemyProject3HUD.h"
#include "UdemyProject3Character.h"
#include "UObject/ConstructorHelpers.h"

AUdemyProject3GameMode::AUdemyProject3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUdemyProject3HUD::StaticClass();
}

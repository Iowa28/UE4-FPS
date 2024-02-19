// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UdemyProject3HUD.generated.h"

UCLASS()
class AUdemyProject3HUD : public AHUD
{
	GENERATED_BODY()

public:
	AUdemyProject3HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


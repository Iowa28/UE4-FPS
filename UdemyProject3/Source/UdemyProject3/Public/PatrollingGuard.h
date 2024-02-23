// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UdemyProject3/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYPROJECT3_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;

public:
	TArray<AActor*> GetPatrolPoints();
};

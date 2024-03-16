// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMYPROJECT3_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActorPool();

	AActor* Checkout();

	void Return(AActor* ActorToReturn);

	void Add(AActor* ActorToAdd);
};

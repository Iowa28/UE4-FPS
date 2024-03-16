// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

UCLASS()
class UDEMYPROJECT3_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, float Radius = 200, float MinScale = 1, float MaxScale = 1);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* ActorPool);

private:
	UActorPool* Pool = nullptr;
	
	bool FindEmptyLocation(FVector& OutLocation, const FBox& Bounds, float Radius);

	void PlaceActor(TSubclassOf<AActor> ClassToSpawn, FVector SpawnPoint, float Angle, float Scale);
	
	bool CanSpawnAtLocation(FVector Location, float Radius);
};

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
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffset= FVector(2000, 0, 0);
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	FVector MinExtent = FVector(0, -2000, 0);
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	FVector MaxExtent = FVector(4000, 2000, 0);
	
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, float Radius = 200, float MinScale = 1, float MaxScale = 1);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* ActorPool);

private:
	UActorPool* Pool = nullptr;

	AActor* NavMeshBoundsVolume = nullptr;

	void PositionNavMeshBoundsVolume();
	
	bool FindEmptyLocation(FVector& OutLocation, const FBox& Bounds, float Radius);

	void PlaceActor(TSubclassOf<AActor> ClassToSpawn, FVector SpawnPoint, float Angle, float Scale);
	
	bool CanSpawnAtLocation(FVector Location, float Radius);
};

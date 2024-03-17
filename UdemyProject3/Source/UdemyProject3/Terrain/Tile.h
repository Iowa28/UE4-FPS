// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_BODY()

	FVector Location;
	float Rotation;
	float Scale;
};

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
	
	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void PlaceActor(const TSubclassOf<AActor> ClassToSpawn, const FSpawnPosition& SpawnPosition);
	
	bool CanSpawnAtLocation(const FVector Location, float Radius);
};

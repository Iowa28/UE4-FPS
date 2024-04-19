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
	float Scale = 1;
};

class UActorPool;

UCLASS()
class UDEMYPROJECT3_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, float Radius = 200, float MinScale = 1, float MaxScale = 1);

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void PlaceAIPawns(const TSubclassOf<APawn> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, float Radius = 200);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* ActorPool);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffset= FVector(2000, 0, 0);
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	FVector MinExtent = FVector(0, -2000, 0);
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	FVector MaxExtent = FVector(4000, 2000, 0);
	
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UActorPool* Pool = nullptr;

	AActor* NavMeshBoundsVolume = nullptr;

	void PositionNavMeshBoundsVolume();
	
	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	template<class T>
	void PlaceActorsRandomly(const TSubclassOf<T> ClassToSpawn, const int32 MinSpawn = 1, const int32 MaxSpawn = 1, float Radius = 200, float MinScale = 1, float MaxScale = 1);

	template<class T>
	void PlaceActor(const TSubclassOf<T> ClassToSpawn, const FSpawnPosition& SpawnPosition);
	
	// void PlaceAIPawn(const TSubclassOf<APawn> ClassToSpawn, const FSpawnPosition& SpawnPosition);

	// template<class T>
	// void PlaceObject(const TSubclassOf<T> ClassToSpawn, const FSpawnPosition& SpawnPosition);
	
	bool CanSpawnAtLocation(const FVector Location, float Radius);
};



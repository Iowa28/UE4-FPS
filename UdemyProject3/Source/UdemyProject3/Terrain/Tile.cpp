// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "DrawDebugHelpers.h"

ATile::ATile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATile::BeginPlay()
{
	Super::BeginPlay();
}

void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATile::PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, const float Radius)
{
	const FVector Min = FVector(0, -2000, 0);
	const FVector Max = FVector(4000, 2000, 0);
	const FBox Bounds = FBox(Min, Max);

	const int32 PointCount = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int32 i = 0; i < PointCount; i++)
	{
		FVector SpawnPoint;
		if (FindEmptyLocation(SpawnPoint, Bounds, Radius))
		{
			PlaceActor(ClassToSpawn, SpawnPoint);
		}
	}
}

bool ATile::FindEmptyLocation(FVector& OutLocation, const FBox& Bounds, const float Radius)
{
	constexpr int32 MaxAttempts = 100;
	for (int32 i = 0; i < MaxAttempts; i++)
	{
		FVector SpawnPoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(SpawnPoint, Radius))
		{
			OutLocation = SpawnPoint;
			return true;
		}
	}
	return false;
}

void ATile::PlaceActor(const TSubclassOf<AActor> ClassToSpawn, const FVector SpawnPoint)
{
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ClassToSpawn);
	SpawnedActor->SetActorRelativeLocation(SpawnPoint);
	SpawnedActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

bool ATile::CanSpawnAtLocation(FVector Location, const float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);

	FColor Color = HasHit ? FColor::Red : FColor::Green;
	DrawDebugCapsule(GetWorld(), GlobalLocation, 0, Radius, FQuat::Identity, Color, true, 10000);
	return !HasHit;
}

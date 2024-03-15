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

void ATile::PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, const float Radius, float MinScale, float MaxScale)
{
	const FVector Min = FVector(0, -2000, 0);
	const FVector Max = FVector(4000, 2000, 0);
	const FBox Bounds = FBox(Min, Max);

	const int32 PointCount = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int32 i = 0; i < PointCount; i++)
	{
		FVector SpawnPoint;
		float RandomScale = FMath::RandRange(MinScale, MaxScale);
		if (FindEmptyLocation(SpawnPoint, Bounds, Radius * RandomScale))
		{
			float RandomAngle = FMath::RandRange(-180.f, 180.f);
			PlaceActor(ClassToSpawn, SpawnPoint, RandomAngle, RandomScale);
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

void ATile::PlaceActor(TSubclassOf<AActor> ClassToSpawn, FVector SpawnPoint, float Angle, float Scale)
{
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ClassToSpawn);
	SpawnedActor->SetActorRelativeLocation(SpawnPoint);
	SpawnedActor->SetActorRelativeRotation(FRotator(0, Angle, 0));
	SpawnedActor->SetActorRelativeScale3D(FVector(Scale));
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
	return !HasHit;
}

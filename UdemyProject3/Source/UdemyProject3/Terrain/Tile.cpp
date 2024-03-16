// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "UdemyProject3/ActorPool.h"

ATile::ATile()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATile::BeginPlay()
{
	Super::BeginPlay();
}

void ATile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	Pool->Return(NavMeshBoundsVolume);
}

void ATile::PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, const float Radius, float MinScale, float MaxScale)
{
	const FBox Bounds = FBox(MinExtent, MaxExtent);

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

void ATile::SetPool(UActorPool* ActorPool)
{
	Pool = ActorPool;

	PositionNavMeshBoundsVolume();
}

void ATile::PositionNavMeshBoundsVolume()
{
	NavMeshBoundsVolume = Pool->Checkout();
	if (NavMeshBoundsVolume)
	{
		NavMeshBoundsVolume->SetActorLocation(GetActorLocation());
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

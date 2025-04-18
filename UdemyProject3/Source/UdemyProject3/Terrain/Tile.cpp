// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "UdemyProject3/ActorPool.h"
#include "NavigationSystem.h"

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
	Pool->Return(NavMeshBoundsVolume);
	
	Super::EndPlay(EndPlayReason);
}

template <class T>
void ATile::PlaceActorsRandomly(const TSubclassOf<T> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn,
								float Radius, float MinScale, float MaxScale)
{
	const int32 NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int32 i = 0; i < NumberToSpawn; i++)
	{
		FSpawnPosition SpawnPosition;
		SpawnPosition.Scale = FMath::RandRange(MinScale, MaxScale);
		bool Found = FindEmptyLocation(SpawnPosition.Location, Radius * SpawnPosition.Scale);
		if (Found)
		{
			SpawnPosition.Rotation = FMath::RandRange(-180.f, 180.f);
			PlaceActor(ClassToSpawn, SpawnPosition);
		}
	}
}

void ATile::PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, const float Radius, float MinScale, float MaxScale)
{
	PlaceActorsRandomly(ClassToSpawn, MinSpawn, MaxSpawn, Radius, MinScale, MaxScale);
}

void ATile::PlaceAIPawns(const TSubclassOf<APawn> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn, float Radius)
{
	PlaceActorsRandomly(ClassToSpawn, MinSpawn, MaxSpawn, Radius, 1, 1);
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
		NavMeshBoundsVolume->SetActorLocation(GetActorLocation() + NavigationBoundsOffset);
		UNavigationSystemV1::GetCurrent(GetWorld())->Build();
	}
}

bool ATile::FindEmptyLocation(FVector& OutLocation, const float Radius)
{
	FBox Bounds = FBox(MinExtent, MaxExtent);
	
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

template<>
void ATile::PlaceActor(const TSubclassOf<AActor> ClassToSpawn, const FSpawnPosition& SpawnPosition)
{
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ClassToSpawn);
	if (SpawnedActor)
	{
		SpawnedActor->SetActorRelativeLocation(SpawnPosition.Location);
		SpawnedActor->SetActorRelativeRotation(FRotator(0, SpawnPosition.Rotation, 0));
		SpawnedActor->SetActorRelativeScale3D(FVector(SpawnPosition.Scale));
		SpawnedActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	}
}

template<>
void ATile::PlaceActor(const TSubclassOf<APawn> ClassToSpawn, const FSpawnPosition& SpawnPosition)
{
	FRotator Rotation = FRotator(0, SpawnPosition.Rotation, 0);
	APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(ClassToSpawn, SpawnPosition.Location, Rotation);
	if (SpawnedPawn)
	{
		SpawnedPawn->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		SpawnedPawn->SpawnDefaultController();
	}
}

bool ATile::CanSpawnAtLocation(const FVector Location, const float Radius)
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

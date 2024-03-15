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
	CastSphere(GetActorLocation(), 300);
	CastSphere(GetActorLocation() + FVector(0, 0, 1000), 300);
}

void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATile::PlaceActors(const TSubclassOf<AActor> ClassToSpawn, const int32 MinSpawn, const int32 MaxSpawn)
{
	const FVector Min = FVector(0, -2000, 0);
	const FVector Max = FVector(4000, 2000, 0);
	const FBox Bounds = FBox(Min, Max);

	const int32 PointCount = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int32 i = 0; i < PointCount; i++)
	{
		FVector RandomPoint = FMath::RandPointInBox(Bounds);
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ClassToSpawn);
		SpawnedActor->SetActorRelativeLocation(RandomPoint);
		SpawnedActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	}
}

bool ATile::CastSphere(FVector Location, float Radius)
{
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Location,
		Location,
		FQuat::Identity,
		ECC_Camera,
		FCollisionShape::MakeSphere(Radius)
	);

	FColor Color = HasHit ? FColor::Red : FColor::Green;
	DrawDebugSphere(GetWorld(), Location, Radius, 16, Color, true, 10000);
	return HasHit;
}

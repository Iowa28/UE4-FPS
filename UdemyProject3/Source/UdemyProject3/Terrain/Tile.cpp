// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"

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

void ATile::PlaceActors()
{
	const FVector Min = FVector(0, -2000, 0);
	const FVector Max = FVector(4000, 2000, 0);
	const FBox Bounds = FBox(Min, Max);

	constexpr int32 PointCount = 20;
	for (int32 i = 0; i < PointCount; i++)
	{
		FVector RandomPoint = FMath::RandPointInBox(Bounds);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *RandomPoint.ToCompactString());
	}
}

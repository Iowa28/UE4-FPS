// Fill out your copyright notice in the Description page of Project Settings.


#include "GrassComponent.h"

UGrassComponent::UGrassComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UGrassComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnGrass();
}

void UGrassComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrassComponent::SpawnGrass()
{
	for (int32 i = 0; i < SpawnCount; i++)
	{
		FVector Location = FMath::RandPointInBox(SpawningExtents);
		AddInstance(FTransform(Location));
	}
}


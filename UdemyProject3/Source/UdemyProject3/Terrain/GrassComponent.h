// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GrassComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UDEMYPROJECT3_API UGrassComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:	
	UGrassComponent();

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FBox SpawningExtents;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	int SpawnCount;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SpawnGrass();
};

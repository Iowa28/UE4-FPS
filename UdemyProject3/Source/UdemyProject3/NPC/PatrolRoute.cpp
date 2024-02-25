// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolRoute.h"

UPatrolRoute::UPatrolRoute()
{
	PrimaryComponentTick.bCanEverTick = false;

	// UE_LOG(LogTemp, Warning, TEXT("Hello"));
}

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const
{
	return PatrolPoints;
}


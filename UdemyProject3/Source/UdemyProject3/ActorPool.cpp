// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

UActorPool::UActorPool()
{
	PrimaryComponentTick.bCanEverTick = true;

	Pool = TArray<AActor*>();
}

AActor* UActorPool::Checkout()
{
	if (Pool.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Actor pool is empty"));
		return nullptr;
	}
	
	return Pool.Pop();
}

void UActorPool::Return(AActor* ActorToReturn)
{
	Add(ActorToReturn);
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd)
	{
		Pool.Push(ActorToAdd);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Returning actor is null"));
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

UActorPool::UActorPool()
{
	PrimaryComponentTick.bCanEverTick = true;

	Pool = TArray<AActor*>();
}

AActor* UActorPool::Checkout()
{
	UE_LOG(LogTemp, Warning, TEXT("Pool size: %d"), Pool.Num());
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
	Pool.Push(ActorToAdd);
}

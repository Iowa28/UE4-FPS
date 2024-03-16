// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

UActorPool::UActorPool()
{
	PrimaryComponentTick.bCanEverTick = true;
}

AActor* UActorPool::Checkout()
{
	return nullptr;
}

void UActorPool::Return(AActor* ActorToReturn)
{
	
}

void UActorPool::Add(AActor* ActorToAdd)
{
	
}

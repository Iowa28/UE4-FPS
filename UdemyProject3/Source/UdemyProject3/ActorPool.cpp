// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

UActorPool::UActorPool()
{
	PrimaryComponentTick.bCanEverTick = true;
}

AActor* UActorPool::Checkout()
{
	return Actor;
}

void UActorPool::Return(AActor* ActorToReturn)
{
	Actor = ActorToReturn;
}

void UActorPool::Add(AActor* ActorToAdd)
{
	Return(ActorToAdd);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// UE_LOG(LogTemp, Warning, TEXT("Hey there"));

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	return EBTNodeResult::Succeeded;
}
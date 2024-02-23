// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"

#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// UE_LOG(LogTemp, Warning, TEXT("Hey there"));
	
	APatrollingGuard* PatrollingGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	TArray<AActor*> PatrolPoints = PatrollingGuard->GetPatrolPoints();

	if (PatrolPoints.Num() == 0)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	int32 NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}

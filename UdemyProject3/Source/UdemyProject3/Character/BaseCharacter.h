// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;
class AGun;

UCLASS()
class UDEMYPROJECT3_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Setup")
	USkeletalMeshComponent* ArmsMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AGun> GunBlueprint;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Setup")
	AGun* Gun;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	// UAnimMontage* ShootAnimation;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void PullTrigger();
};

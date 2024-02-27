// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class UDEMYPROJECT3_API AGun : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	USceneComponent* FP_MuzzleLocation;
	
public:	
	AGun();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class ABallProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	UAnimMontage* FireAnimation;
	
	virtual void Tick(float DeltaTime) override;

	void Fire();

	void SetAnimInstance(UAnimInstance* AnimationInstance);

private:
	UAnimInstance* AnimInstance = nullptr;
	
};

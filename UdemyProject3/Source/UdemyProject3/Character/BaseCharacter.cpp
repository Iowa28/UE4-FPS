// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "UdemyProject3/Weapons/Gun.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(-4.5f, -4.f, 64.f));
	CameraComponent->bUsePawnControlRotation = true;
	
	ArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Arms"));
	ArmsMesh->SetOnlyOwnerSee(true);
	ArmsMesh->SetupAttachment(CameraComponent);
	ArmsMesh->bCastDynamicShadow = false;
	ArmsMesh->CastShadow = false;
	ArmsMesh->SetRelativeRotation(FRotator(1.8f, -19.2f, 5.2f));
	ArmsMesh->SetRelativeLocation(FVector(2.8f, -6.7f, -160.3f));
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!GunBlueprint)
	{
		return;
	}

	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	if (IsPlayerControlled())
	{
		Gun->AttachToComponent(ArmsMesh, FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), TEXT("GripPoint"));
	}
	else
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), TEXT("GripPoint"));
	}
	Gun->SetAnimInstanceFP(ArmsMesh->GetAnimInstance());
	Gun->SetAnimInstanceTP(GetMesh()->GetAnimInstance());

	if (InputComponent)
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &ABaseCharacter::PullTrigger);
	}
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::UnPossessed()
{
	Super::UnPossessed();

	if (Gun)
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), TEXT("GripPoint"));
	}
}

void ABaseCharacter::PullTrigger()
{
	Gun->Fire();
}

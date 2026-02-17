// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AHPlayerCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AAHPlayerCharacterBase::AAHPlayerCharacterBase()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true; 
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false; 
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->SetupAttachment(RootComponent);
	springArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 180.0f, 0.0f), FRotator(-45.0f, 0.0f, 0.0f));
	springArmComp->TargetArmLength = 1200.0f;
	
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp")); 
	cameraComp->SetupAttachment(springArmComp);
}

void AAHPlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

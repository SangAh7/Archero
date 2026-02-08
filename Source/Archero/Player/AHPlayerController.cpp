// Fill out your copyright notice in the Description page of Project Settings.
#include "EnhancedInputSubsystems.h"
#include "Player/AHPlayerController.h"

AAHPlayerController::AAHPlayerController()
{
	bReplicates = true; 


}

void AAHPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AHContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem);

	Subsystem->AddMappingContext(AHContext, 0);

	bShowMouseCursor = true; 
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

// Fill out your copyright notice in the Description page of Project Settings.
#include "Player/AHPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Controller.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "Interaction/EnemyInterface.h"
#include "Engine/HitResult.h"

AAHPlayerController::AAHPlayerController()
{
	bReplicates = true; 


}

void AAHPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
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

void AAHPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent;

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAHPlayerController::Move);
}

void AAHPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);


	const FVector ForWardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector   RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);


	if (APawn* ControlledPawn =  GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForWardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(  RightDirection, InputAxisVector.X);
	}
}

void AAHPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return; 

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/*
	1.마우스가 아니라 캐릭터가 바라보는 방향으로 바꾸기
	2.캐릭터 하이라이트가 아니라 동그라미로 오브젝트로 바꾸기
	3.생각해봐~~~
	*/
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightActor();

		}
		else
		{
			
		}
	}
	else
	{
		if (ThisActor == nullptr)
		{
			LastActor->UnHighlightActor();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				
			}
		}
	}
}

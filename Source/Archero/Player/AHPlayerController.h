// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AHPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue; 
class IEnemyInterface;


/**
 * 
 */
UCLASS()
class ARCHERO_API AAHPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAHPlayerController();
	virtual void PlayerTick(float DeltaTime);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override; 

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AHContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

private:
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AHPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class ARCHERO_API AAHPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAHPlayerController();


protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<UInputMappingContext> AHContext;


};

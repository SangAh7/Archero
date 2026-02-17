// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AHCharacterBase.h"
#include "AHPlayerCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class ARCHERO_API AAHPlayerCharacterBase : public AAHCharacterBase
{
	GENERATED_BODY()

public:
	AAHPlayerCharacterBase();
	
	virtual void BeginPlay() override;

public:



public:
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<class UCameraComponent> cameraComp;

	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<class USpringArmComponent> springArmComp;
};

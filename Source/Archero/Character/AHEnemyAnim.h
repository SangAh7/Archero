// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AHEnemyAnim.generated.h"

/**
 * 
 */
UCLASS()
class ARCHERO_API UAHEnemyAnim : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UAHEnemyAnim();


public:

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	class AAHEnemyBase* enemy = nullptr; 

	UPROPERTY()
	class UCharacterMovementComponent* movementComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	float speed = 0.0f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	FVector velocity; 
};

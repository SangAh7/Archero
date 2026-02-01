// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AHCharacterBase.generated.h"

UCLASS(Abstract)
class ARCHERO_API AAHCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	AAHCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

public:

	UPROPERTY(EditAnywhere, Category = "CharacterBase")
	float baseAttack; 

	UPROPERTY(EditAnywhere, Category = "CharacterBase")
	float baseAttackSpeed; 

	UPROPERTY(EditAnywhere, Category = "CharacterBase")
	float baseMoveSpeed;

	UPROPERTY(EditAnywhere, Category = "CharacterBase")
	float baseAttackCount; 

	UPROPERTY(EditAnywhere, Category = "CharacterBase")
	float baseCurHP;

	UPROPERTY(EditAnywhere, Category = "CharacterBase")
	float baseMaxHP;

};

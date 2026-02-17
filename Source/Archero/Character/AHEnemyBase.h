// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AHCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AHEnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class ARCHERO_API AAHEnemyBase : public AAHCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAHEnemyBase();
	

public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	

};

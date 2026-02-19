// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AHEnemyBase.h"
#include "Archero.h"
#include "AbilitySystem/AHAbilitySystemComponent.h"
#include "AbilitySystem/AHAttributeSet.h"

AAHEnemyBase::AAHEnemyBase()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAHAbilitySystemComponent>(TEXT("AbilitysystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	/*
	Full : Single Player
	Mixed : Multiplayer, Player_Controlled
	Minimal : MultiPlayer, AI_Controlled
	*/

	AttributeSet = CreateDefaultSubobject<UAHAttributeSet>(TEXT("AttributeSet"));
}


void AAHEnemyBase::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAHEnemyBase::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AAHEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
}

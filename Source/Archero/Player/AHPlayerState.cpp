// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AHPlayerState.h"
#include "AbilitySystem/AHAbilitySystemComponent.h"
#include "AbilitySystem/AHAttributeSet.h"

AAHPlayerState::AAHPlayerState()
{
	AbilitysystemComponent = CreateDefaultSubobject<UAHAbilitySystemComponent>(TEXT("AbilitysystemComponent"));
	AbilitysystemComponent->SetIsReplicated(true);
	AbilitysystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	/*
	Full : Single Player
	Mixed : Multiplayer, Player_Controlled
	Minimal : MultiPlayer, AI_Controlled
	*/
	AttributeSet = CreateDefaultSubobject<UAHAttributeSet>(TEXT("AttributeSet"));


	NetUpdateFrequency = 100.0f; // 서버업데이트 빈도 
}

UAbilitySystemComponent* AAHPlayerState::GetAbilitySystemComponent() const
{
	return AbilitysystemComponent;
}

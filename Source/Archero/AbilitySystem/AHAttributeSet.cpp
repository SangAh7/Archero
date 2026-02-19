// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AHAttributeSet.h"
#include "Net/UnrealNetwork.h"

UAHAttributeSet::UAHAttributeSet()
{
	InitHealth(50.0f);
	InitMaxHealth(100.0f);
}

void UAHAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAHAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAHAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UAHAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAHAttributeSet, Health, OldHealth);
}

#include "AbilitySystemComponent.h"
void UAHAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAHAttributeSet, MaxHealth, OldMaxHealth);
}

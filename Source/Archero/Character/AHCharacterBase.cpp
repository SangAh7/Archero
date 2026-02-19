// Fill out your copyright notice in the Description page of Project Settings.


#include "AHCharacterBase.h"


// Sets default values
AAHCharacterBase::AAHCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);	
}

UAbilitySystemComponent* AAHCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void AAHCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}


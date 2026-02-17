// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AHEnemyAnim.h"
#include "AHEnemyBase.h"

UAHEnemyAnim::UAHEnemyAnim()
{

}

void UAHEnemyAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	enemy = Cast<AAHEnemyBase>(TryGetPawnOwner());

	if (enemy)
	{
		movementComp = enemy->GetCharacterMovement();
		UE_LOG(LogTemp, Warning, TEXT("it is"));

	}
}

void UAHEnemyAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeInitializeAnimation();

	if (enemy)
	{
		velocity = enemy->GetVelocity();
		speed = velocity.Length();

	}
}

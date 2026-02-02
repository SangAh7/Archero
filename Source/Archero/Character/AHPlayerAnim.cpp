// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AHPlayerAnim.h"
#include "AHPlayerCharacterBase.h"

UAHPlayerAnim::UAHPlayerAnim()
{

}

void UAHPlayerAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	player = Cast<AAHPlayerCharacterBase> (TryGetPawnOwner());
	
	if (player)
	{
		movementComp = player->GetCharacterMovement(); 
	}
	
}

void UAHPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (player)
	{
		velocity = player->GetVelocity();
		speed = velocity.Length();

	}
}

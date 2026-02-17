// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AHEnemyBase.h"
#include "Archero.h"

AAHEnemyBase::AAHEnemyBase()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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

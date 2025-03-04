// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/EnemyAnimInstance.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTags.h"

void UEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UEnemyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (OwningCharacter)
	{
		bIsStrafing = URogueTowerFunctionLibrary::NativeDoseActorHaveTag(TryGetPawnOwner(), RogueTowerTag::Enemy_Status_Strafing);
	}
}
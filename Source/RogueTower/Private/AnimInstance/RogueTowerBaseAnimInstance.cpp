// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/RogueTowerBaseAnimInstance.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

void URogueTowerBaseAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ARogueTowerPlayerCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void URogueTowerBaseAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f;
	LocomationDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}

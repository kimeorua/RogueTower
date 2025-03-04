// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/RogueTowerBaseAnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROGUETOWER_API UEnemyAnimInstance : public URogueTowerBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data|LocomationData")
	bool bIsStrafing;
};

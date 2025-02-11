// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/RogueTowerBaseAnimInstance.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROGUETOWER_API UPlayerAnimInstance : public URogueTowerBaseAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anim Data|LocomationData")
	ERogueTowerEquipedWeaponMode EquipedWeaponMode = ERogueTowerEquipedWeaponMode::None;

	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;
};

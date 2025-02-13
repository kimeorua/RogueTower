// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Ability/RogueTowerGameplayAbility.h"
#include "RogueTowerPlayerGameplayAbility.generated.h"

class ARogueTowerPlayerCharacter;
class ARogueTowerPlayerController;
class UPlayerCombetComponent;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API URogueTowerPlayerGameplayAbility : public URogueTowerGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Wrroir | Ability")
	ARogueTowerPlayerCharacter* GetRogueTowerPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Wrroir | Ability")
	ARogueTowerPlayerController* GetRogueTowerPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Wrroir | Ability")
	UPlayerCombetComponent* GetPlayerCombetComponentFromActorInfo();

private:
	TWeakObjectPtr<ARogueTowerPlayerCharacter> CachedRogueTowerPlayerCharacter;
	TWeakObjectPtr<ARogueTowerPlayerController> CachedRogueTowerPlayerController;
};

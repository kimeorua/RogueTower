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

	UFUNCTION(BlueprintPure, Category = "Rogue Tower | Ability")
	ARogueTowerPlayerCharacter* GetRogueTowerPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Rogue Tower | Ability")
	ARogueTowerPlayerController* GetRogueTowerPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Rogue Tower | Ability")
	UPlayerCombetComponent* GetPlayerCombetComponentFromActorInfo();

private:
	TWeakObjectPtr<ARogueTowerPlayerCharacter> CachedRogueTowerPlayerCharacter;
	TWeakObjectPtr<ARogueTowerPlayerController> CachedRogueTowerPlayerController;
};

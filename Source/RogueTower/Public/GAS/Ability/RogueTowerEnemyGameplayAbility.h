// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Ability/RogueTowerGameplayAbility.h"
#include "RogueTowerEnemyGameplayAbility.generated.h"

class ARogueTowerEnemyCharacter;
class UEnemyCombetComponent;
class AEnemyAIController;

UCLASS()
class ROGUETOWER_API URogueTowerEnemyGameplayAbility : public URogueTowerGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "RogueTower | Ability")
	ARogueTowerEnemyCharacter* GetRogueTowerEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "RogueTower | Ability")
	AEnemyAIController* GetRogueToweEnemyrControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "RogueTower | Ability")
	UEnemyCombetComponent* GetEnemyCombetComponentFromActorInfo();

private:
	TWeakObjectPtr<ARogueTowerEnemyCharacter> CachedRogueTowerEnemyCharacter;
	TWeakObjectPtr<AEnemyAIController> CachedRogueTowerEnemyController;
};

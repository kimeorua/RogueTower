// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "DataAsset_StartUpEnemy.generated.h"

class UGameplayEffect;
class URogueTowerEnemyGameplayAbility;

UCLASS()
class ROGUETOWER_API UDataAsset_StartUpEnemy : public UDataAsset_StartUpBase
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel = 1) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UGameplayEffect>>StartUpGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<URogueTowerEnemyGameplayAbility>> ActivateOnceEnemyAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<URogueTowerEnemyGameplayAbility>> EnemyAbilities;

private:
	void GiveEnemyAbilities(const TArray<TSubclassOf<URogueTowerEnemyGameplayAbility>> InGiveAbilities, URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel);
};
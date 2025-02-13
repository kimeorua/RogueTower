// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RogueTowerTypes/RogueTowerStructTypes.h"
#include "RogueTowerAbilitySystemComponent.generated.h"

UCLASS()
class ROGUETOWER_API URogueTowerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "RogueTower|Ability")
	bool TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate);
};

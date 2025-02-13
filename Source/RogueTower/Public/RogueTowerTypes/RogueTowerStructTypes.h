// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"
#include "RogueTowerStructTypes.generated.h"

class URogueTowerPlayerGameplayAbility;

USTRUCT(BlueprintType)
struct FPlayerAbilitySet
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<URogueTowerPlayerGameplayAbility> AbilityToGrant;

	bool IsVaild()const;
};
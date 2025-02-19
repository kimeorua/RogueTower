// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"
#include "RogueTowerStructTypes.generated.h"

class URogueTowerPlayerGameplayAbility;
class UInputMappingContext;

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

USTRUCT(BlueprintType)
struct FRogueTowerWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FPlayerAbilitySet>WeaponAbility;
};
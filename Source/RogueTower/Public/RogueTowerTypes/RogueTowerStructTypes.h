// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"
#include "RogueTowerStructTypes.generated.h"

class URogueTowerPlayerGameplayAbility;
class UInputMappingContext;
class UGameplayEffect;

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
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FPlayerAbilitySet>WeaponAbility;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UGameplayEffect>>StartUpGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Icon")
	TSoftObjectPtr<UTexture2D> WeaponIcon;
};
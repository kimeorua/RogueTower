// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"
#include "RogueTowerStructTypes.generated.h"

class URogueTowerPlayerGameplayAbility;
class ARogueTowerEnemyCharacter;
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StartUpData")
	TSubclassOf<URogueTowerPlayerGameplayAbility> DeathAbility;
};

USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<ARogueTowerEnemyCharacter> EnemyClass;

	UPROPERTY(EditAnywhere)
	TArray<FVector> SpawnLocation;

	UPROPERTY(EditAnywhere)
	int32 SpawnedEnemyNum = 3;
};

USTRUCT(BlueprintType)
struct FEnemySpawnInfoTableRaw : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FEnemySpawnInfo>EnemySpawnerInfo;

	UPROPERTY(EditAnywhere)
	int32 StageNum = 1;
};

USTRUCT(BlueprintType)
struct FStatusUpData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> StatusUpEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 EffectLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString EffectName;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Combet/PawnCombetComponent.h"
#include "PlayerCombetComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSeletedWeaponDelegate, const UDataAsset_WeaponConfig*, WeaponData);

class UDataAsset_WeaponConfig;
class ARogueTowerWeapon;
class ARogueTowerBaseCharacter;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API UPlayerCombetComponent : public UPawnCombetComponent
{
	GENERATED_BODY()
	
public:
	UPlayerCombetComponent();

	UPROPERTY(BlueprintCallable)
	FOnSeletedWeaponDelegate OnSeletedWeaponDelegate;

private:
	UFUNCTION()
	void WeaponTagAdd();

	UFUNCTION()
	void SpawnAndAttachWeapon(const UDataAsset_WeaponConfig* WeaponDataConfig);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	TMap<ERogueTowerWeaponType, ARogueTowerWeapon*> WeaponMap;
};

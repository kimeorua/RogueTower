// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PawnExtensionComponentBase.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "PawnCombetComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSeletedWeaponDelegate, const UDataAsset_WeaponConfig*, WeaponData);

class UDataAsset_WeaponConfig;
class ARogueTowerWeapon;
class ARogueTowerBaseCharacter;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API UPawnCombetComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UPawnCombetComponent();

	UPROPERTY(BlueprintCallable)
	FOnSeletedWeaponDelegate OnSeletedWeaponDelegate;

	virtual void WeaponTagAdd();

private:
	UFUNCTION()
	void SpawnAndAttachWeapon(const UDataAsset_WeaponConfig* WeaponDataConfig);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	TMap<ERogueTowerWeaponType, ARogueTowerWeapon*> WeaponMap;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PawnExtensionComponentBase.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "PawnCombetComponent.generated.h"

class UDataAsset_WeaponConfig;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSeletedWeaponDelegate, const UDataAsset_WeaponConfig*, WeaponData);

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

private:
	UFUNCTION()
	void SpawnAndAttachWeapon(const UDataAsset_WeaponConfig* WeaponDataConfig);
};

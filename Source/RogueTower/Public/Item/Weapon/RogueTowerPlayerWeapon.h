// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Weapon/RogueTowerWeapon.h"
#include "RogueTowerTypes/RogueTowerStructTypes.h"
#include "RogueTowerPlayerWeapon.generated.h"

/**
 * 
 */
UCLASS()
class ROGUETOWER_API ARogueTowerPlayerWeapon : public ARogueTowerWeapon
{
	GENERATED_BODY()

public:
	ARogueTowerPlayerWeapon();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Data")
	FRogueTowerWeaponData WeaponData;
};

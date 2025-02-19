// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/RogueTowerItemBase.h"
#include "RogueTowerTypes/RogueTowerStructTypes.h"
#include "RogueTowerWeapon.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API ARogueTowerWeapon : public ARogueTowerItemBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Collision", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* WeaponCollision;

public:
	ARogueTowerWeapon();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Data")
	FRogueTowerWeaponData WeaponData;
};

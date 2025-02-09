// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/RogueTowerItemBase.h"
#include "RogueTowerWeapon.generated.h"

class USkeletalMeshComponent;
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
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Collision", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* WeaponCollision;

public:
	ARogueTowerWeapon();
};

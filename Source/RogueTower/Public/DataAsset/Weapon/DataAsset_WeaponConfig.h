// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "Item/Weapon/RogueTowerPlayerWeapon.h"
#include "DataAsset_WeaponConfig.generated.h"

class ARogueTowerPlayerWeapon;
class URogueTowerBaseAnimInstance;

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ARogueTowerPlayerWeapon>WeaponClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WeaponAttachmentSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ERogueTowerWeaponType WeaponType = ERogueTowerWeaponType::None;

	bool IsValud() const
	{
		return IsValid(WeaponClass); 
	}
};

/**
 * 
 */
UCLASS()
class ROGUETOWER_API UDataAsset_WeaponConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FWeaponData> WeaponDatas;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> WeaponAnimBP;
};
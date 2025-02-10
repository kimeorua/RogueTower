// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PawnCombetComponent.h"
#include "DataAsset/Weapon/DataAsset_WeaponConfig.h"

#include "DebugHelper.h"

UPawnCombetComponent::UPawnCombetComponent()
{
	OnSeletedWeaponDelegate.AddDynamic(this, &ThisClass::SpawnAndAttachWeapon);
}

void UPawnCombetComponent::SpawnAndAttachWeapon(const UDataAsset_WeaponConfig* WeaponDataConfig)
{
	for (const FWeaponData WeaponData : WeaponDataConfig->WeaponDatas)
	{
		//TODO: 무기 스폰 및 소켓에 부착
		if (WeaponData.IsValud())
		{
			Debug::Print("Weapon is valid", FColor::Red);
		}
		else
		{
			Debug::Print("WeaponData is not valid", FColor::Red);
		}
	}
}

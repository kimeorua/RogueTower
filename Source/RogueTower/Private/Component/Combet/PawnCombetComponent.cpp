// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PawnCombetComponent.h"
#include "DataAsset/Weapon/DataAsset_WeaponConfig.h"
#include "Character/RogueTowerBaseCharacter.h"

#include "DebugHelper.h"

UPawnCombetComponent::UPawnCombetComponent()
{
	OnSeletedWeaponDelegate.AddDynamic(this, &ThisClass::SpawnAndAttachWeapon);
}

void UPawnCombetComponent::WeaponTagAdd()
{
}

void UPawnCombetComponent::SpawnAndAttachWeapon(const UDataAsset_WeaponConfig* WeaponDataConfig)
{
	ARogueTowerBaseCharacter* OwnerCharacter = Cast<ARogueTowerBaseCharacter>(GetOwner());

	if (!OwnerCharacter) { return; }
		
	for (const FWeaponData& WeaponData : WeaponDataConfig->WeaponDatas)
	{
		if (WeaponData.IsValud())
		{
			ARogueTowerWeapon* SpawnedWeapon = GetWorld()->SpawnActor<ARogueTowerWeapon>(WeaponData.WeaponClass);
			WeaponMap.Add(WeaponData.WeaponType, SpawnedWeapon);

			SpawnedWeapon->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponData.WeaponAttachmentSocketName);
			
		}
		else
		{
			Debug::Print("WeaponData is not valid", FColor::Red);
		}
	}
	WeaponTagAdd();
}

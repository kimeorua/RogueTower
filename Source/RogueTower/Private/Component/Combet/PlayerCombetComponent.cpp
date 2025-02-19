// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PlayerCombetComponent.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTags.h"
#include "DataAsset/Weapon/DataAsset_WeaponConfig.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "Item/Weapon/RogueTowerWeapon.h"

UPlayerCombetComponent::UPlayerCombetComponent()
{
	OnSeletedWeaponDelegate.AddDynamic(this, &ThisClass::SpawnAndAttachWeapon);
}

void UPlayerCombetComponent::WeaponTagAdd()
{
	ARogueTowerPlayerCharacter* OwnerCharacter = Cast<ARogueTowerPlayerCharacter>(GetOwner());
	ARogueTowerWeapon* Weapon;

	if (WeaponMap.Contains(ERogueTowerWeaponType::TwoHanded))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::TwoHanded);
		Cast<URogueTowerAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent())->GrantHeroWeaponAbilities(Weapon->WeaponData.WeaponAbility, 1);
		OwnerCharacter->AddInputContext(Weapon->WeaponData.WeaponInputMappingContext);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Duall_L) || WeaponMap.Contains(ERogueTowerWeaponType::Duall_R))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::Duall_L);
		Cast<URogueTowerAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent())->GrantHeroWeaponAbilities(Weapon->WeaponData.WeaponAbility, 1);
		OwnerCharacter->AddInputContext(Weapon->WeaponData.WeaponInputMappingContext);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Katana) || WeaponMap.Contains(ERogueTowerWeaponType::Katana_Sheath))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::Katana);
		Cast<URogueTowerAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent())->GrantHeroWeaponAbilities(Weapon->WeaponData.WeaponAbility, 1);
		OwnerCharacter->AddInputContext(Weapon->WeaponData.WeaponInputMappingContext);
	}
	else
	{
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
	}
}

void UPlayerCombetComponent::SpawnAndAttachWeapon(const UDataAsset_WeaponConfig* WeaponDataConfig)
{
	ARogueTowerPlayerCharacter* OwnerCharacter = Cast<ARogueTowerPlayerCharacter>(GetOwner());

	if (!OwnerCharacter) { return; }

	for (const FWeaponData& WeaponClassData : WeaponDataConfig->WeaponDatas)
	{
		if (WeaponClassData.IsValud())
		{
			ARogueTowerWeapon* SpawnedWeapon = GetWorld()->SpawnActor<ARogueTowerWeapon>(WeaponClassData.WeaponClass);
			WeaponMap.Add(WeaponClassData.WeaponType, SpawnedWeapon);

			SpawnedWeapon->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponClassData.WeaponAttachmentSocketName);
			//Cast<URogueTowerAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent())->GrantHeroWeaponAbilities(SpawnedWeapon->WeaponData.WeaponAbility, 1);
		}
	}
	if (IsValid(WeaponDataConfig->WeaponAnimBP))
	{
		OwnerCharacter->GetMesh()->LinkAnimClassLayers(WeaponDataConfig->WeaponAnimBP);
	}

	WeaponTagAdd();
}

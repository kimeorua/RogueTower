// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PlayerCombetComponent.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTags.h"
#include "DataAsset/Weapon/DataAsset_WeaponConfig.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "Item/Weapon/RogueTowerPlayerWeapon.h"

UPlayerCombetComponent::UPlayerCombetComponent()
{
	OnSeletedWeaponDelegate.AddDynamic(this, &ThisClass::SpawnAndAttachWeapon);
}

ARogueTowerPlayerWeapon* UPlayerCombetComponent::GetWeapon(bool IsLeft) const
{
	if (WeaponMap.Contains(ERogueTowerWeaponType::TwoHanded))
	{
		return WeaponMap.FindRef(ERogueTowerWeaponType::TwoHanded);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Duall_L) || WeaponMap.Contains(ERogueTowerWeaponType::Duall_R))
	{
		if (IsLeft)
		{
			return WeaponMap.FindRef(ERogueTowerWeaponType::Duall_L);
		}
		else
		{
			return WeaponMap.FindRef(ERogueTowerWeaponType::Duall_R);
		}
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Katana) || WeaponMap.Contains(ERogueTowerWeaponType::Katana_Sheath))
	{
		return WeaponMap.FindRef(ERogueTowerWeaponType::Katana);
	}
	return nullptr;
}

void UPlayerCombetComponent::WeaponTagAdd()
{
	ARogueTowerPlayerCharacter* OwnerCharacter = Cast<ARogueTowerPlayerCharacter>(GetOwner());
	ARogueTowerPlayerWeapon* Weapon = nullptr;
	URogueTowerAbilitySystemComponent* ASC = Cast<URogueTowerAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent());

	if (WeaponMap.Contains(ERogueTowerWeaponType::TwoHanded))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::TwoHanded);
		ASC->GrantHeroWeaponAbilities(Weapon->WeaponData.WeaponAbility, 1);
		OwnerCharacter->AddInputContext(Weapon->WeaponData.WeaponInputMappingContext);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Duall_L) || WeaponMap.Contains(ERogueTowerWeaponType::Duall_R))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::Duall_L);
		ASC->GrantHeroWeaponAbilities(Weapon->WeaponData.WeaponAbility, 1);
		OwnerCharacter->AddInputContext(Weapon->WeaponData.WeaponInputMappingContext);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Katana) || WeaponMap.Contains(ERogueTowerWeaponType::Katana_Sheath))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::Katana);
		ASC->GrantHeroWeaponAbilities(Weapon->WeaponData.WeaponAbility, 1);
		OwnerCharacter->AddInputContext(Weapon->WeaponData.WeaponInputMappingContext);
	}
	else
	{
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
	}

	if (ASC && Weapon)
	{
		ApplayStartUpEffect(ASC, Weapon);
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
			ARogueTowerPlayerWeapon* SpawnedWeapon = GetWorld()->SpawnActor<ARogueTowerPlayerWeapon>(WeaponClassData.WeaponClass);
			WeaponMap.Add(WeaponClassData.WeaponType, SpawnedWeapon);

			SpawnedWeapon->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponClassData.WeaponAttachmentSocketName);
			SpawnedWeapon->SetOwner(OwnerCharacter);
		}
	}
	if (IsValid(WeaponDataConfig->WeaponAnimBP))
	{
		OwnerCharacter->GetMesh()->LinkAnimClassLayers(WeaponDataConfig->WeaponAnimBP);
	}
	WeaponTagAdd();
}

void UPlayerCombetComponent::ApplayStartUpEffect(URogueTowerAbilitySystemComponent* ASC, ARogueTowerPlayerWeapon* Weapon)
{
	if (!(Weapon->WeaponData.StartUpGameplayEffects.IsEmpty()))
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : Weapon->WeaponData.StartUpGameplayEffects)
		{
			if (!EffectClass) { continue; }
			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			ASC->ApplyGameplayEffectToSelf(EffectCDO, 1, ASC->MakeEffectContext());
		}
	}
}

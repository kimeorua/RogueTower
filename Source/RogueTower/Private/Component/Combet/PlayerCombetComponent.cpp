// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PlayerCombetComponent.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTags.h"
#include "DataAsset/Weapon/DataAsset_WeaponConfig.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "Item/Weapon/RogueTowerPlayerWeapon.h"
#include "Component/UI/PlayerUIComponent.h"
#include "GAS/Ability/RogueTowerPlayerGameplayAbility.h"

#include "DebugHelper.h"

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

void UPlayerCombetComponent::CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate)
{
	ARogueTowerPlayerWeapon* CurrentWeapon = nullptr;

	switch (Type)
	{
	case ERogueTowerCombetCollisionType::WeaponLeft:
		CurrentWeapon = GetWeapon(true);
		break;

	case ERogueTowerCombetCollisionType::WeaponRight:
		CurrentWeapon = GetWeapon(false);
		break;

	default:
		break;
	}

	if (!CurrentWeapon) { return; }

	if (Activate)
	{
		CurrentWeapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		CurrentWeapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OverlapedActors.Empty();
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

			SpawnedWeapon->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
		}
	}
	if (IsValid(WeaponDataConfig->WeaponAnimBP))
	{
		OwnerCharacter->GetMesh()->LinkAnimClassLayers(WeaponDataConfig->WeaponAnimBP);
	}
	WeaponTagAdd();
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

		WeaponDataSetting(OwnerCharacter, Weapon, ASC);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Duall_L) || WeaponMap.Contains(ERogueTowerWeaponType::Duall_R))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::Duall_L);

		WeaponDataSetting(OwnerCharacter, Weapon, ASC);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Katana) || WeaponMap.Contains(ERogueTowerWeaponType::Katana_Sheath))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		Weapon = WeaponMap.FindRef(ERogueTowerWeaponType::Katana);

		WeaponDataSetting(OwnerCharacter, Weapon, ASC);
	}
	else
	{
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
	}

	if (ASC && Weapon)
	{
		ASC->TryActivateAbilityByTag(RogueTowerTag::Player_Ability_DrawUI);

		if (Weapon->WeaponData.WeaponIcon)
		{
			OwnerCharacter->GetPlayerUIComponent()->OnWeaponIconChanged.Broadcast(Weapon->WeaponData.WeaponIcon);
		}
		ApplayStartUpEffect(ASC, Weapon);
	}
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

void UPlayerCombetComponent::WeaponDataSetting(ARogueTowerPlayerCharacter* InPlayer, ARogueTowerPlayerWeapon* InWeapon, URogueTowerAbilitySystemComponent* InASC)
{
	if (InPlayer && InWeapon && InASC)
	{
		InASC->GrantHeroWeaponAbilities(InWeapon->WeaponData.WeaponAbility, 1);

		FGameplayAbilitySpec AbilitySpec(InWeapon->WeaponData.DeathAbility);
		AbilitySpec.SourceObject = InPlayer;
		AbilitySpec.Level = 1;

		InASC->GiveAbility(AbilitySpec);

		InPlayer->AddInputContext(InWeapon->WeaponData.WeaponInputMappingContext);
	}
}
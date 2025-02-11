// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PlayerCombetComponent.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTags.h"

UPlayerCombetComponent::UPlayerCombetComponent()
{
}

void UPlayerCombetComponent::WeaponTagAdd()
{
	if (WeaponMap.Contains(ERogueTowerWeaponType::TwoHanded))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Duall_L) || WeaponMap.Contains(ERogueTowerWeaponType::Duall_R))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
	}
	else if (WeaponMap.Contains(ERogueTowerWeaponType::Katana) || WeaponMap.Contains(ERogueTowerWeaponType::Katana_Sheath))
	{
		URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
	}
	else
	{
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_Katana);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_DualBlade);
		URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(GetOwner(), RogueTowerTag::Player_Weapon_GreateSword);
	}
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class ERogueTowerWeaponType : uint8
{
	None,
	TwoHanded,
	Duall_L,
	Duall_R,
	Katana,
	Katana_Sheath
};

UENUM(BlueprintType)
enum class ERogueTowerInputMode : uint8
{
	GameOnly,
	UIOnly
};

UENUM()
enum class ERogueTowerConfirmType : uint8
{
	Yes,
	No
};

UENUM(BlueprintType)
enum class ERogueTowerEquipedWeaponMode : uint8
{
	None,
	GreatSword,
	DuallBlade,
	Katana
};

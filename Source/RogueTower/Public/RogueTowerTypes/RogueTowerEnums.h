// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class ERogueTowerWeaponType : uint8
{
	TwoHanded,
	Duall,
	Katana,
};

UENUM(BlueprintType)
enum class ERogueTowerInputMode : uint8
{
	GameOnly,
	UIOnly
};
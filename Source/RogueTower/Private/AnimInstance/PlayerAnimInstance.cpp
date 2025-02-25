// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerAnimInstance.h"
#include "RogueTowerFunctionLibrary.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "RogueTowerTags.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningCharacter = Cast<ARogueTowerPlayerCharacter>(TryGetPawnOwner());
}

void UPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	if (OwningCharacter)
	{
		if (URogueTowerFunctionLibrary::NativeDoseActorHaveTag(TryGetPawnOwner(), RogueTowerTag::Player_Weapon_GreateSword))
		{
			EquipedWeaponMode = ERogueTowerEquipedWeaponMode::GreatSword;
		}
		else if (URogueTowerFunctionLibrary::NativeDoseActorHaveTag(TryGetPawnOwner(), RogueTowerTag::Player_Weapon_DualBlade))
		{
			EquipedWeaponMode = ERogueTowerEquipedWeaponMode::DuallBlade;
		}
		else if (URogueTowerFunctionLibrary::NativeDoseActorHaveTag(TryGetPawnOwner(), RogueTowerTag::Player_Weapon_Katana))
		{
			EquipedWeaponMode = ERogueTowerEquipedWeaponMode::Katana;
		}
		else
		{
			EquipedWeaponMode = ERogueTowerEquipedWeaponMode::None;
		}
	}
}

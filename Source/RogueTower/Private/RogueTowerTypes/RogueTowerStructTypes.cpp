// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueTowerTypes/RogueTowerStructTypes.h"
#include "GAS/Ability/RogueTowerPlayerGameplayAbility.h"


bool FPlayerAbilitySet::IsVaild() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

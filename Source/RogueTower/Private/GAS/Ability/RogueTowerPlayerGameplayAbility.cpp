// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/RogueTowerPlayerGameplayAbility.h"
#include "Controller/RogueTowerPlayerController.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "Component/Combet/PlayerCombetComponent.h"

ARogueTowerPlayerCharacter* URogueTowerPlayerGameplayAbility::GetRogueTowerPlayerCharacterFromActorInfo()
{
	if (!CachedRogueTowerPlayerCharacter.IsValid())
	{
		CachedRogueTowerPlayerCharacter = Cast<ARogueTowerPlayerCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedRogueTowerPlayerCharacter.IsValid() ? CachedRogueTowerPlayerCharacter.Get() : nullptr;
}

ARogueTowerPlayerController* URogueTowerPlayerGameplayAbility::GetRogueTowerPlayerControllerFromActorInfo()
{
	if (!CachedRogueTowerPlayerController.IsValid())
	{
		CachedRogueTowerPlayerController = Cast<ARogueTowerPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedRogueTowerPlayerController.IsValid() ? CachedRogueTowerPlayerController.Get() : nullptr;
}

UPlayerCombetComponent* URogueTowerPlayerGameplayAbility::GetPlayerCombetComponentFromActorInfo()
{
	return GetRogueTowerPlayerCharacterFromActorInfo()->GetPlayerCombetComponent();
}
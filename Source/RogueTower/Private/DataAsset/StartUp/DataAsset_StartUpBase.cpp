// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "GAS/Ability/RogueTowerPlayerGameplayAbility.h"

void UDataAsset_StartUpBase::GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel)
{
	check(InAbilitySystemToGive);
	GrantAbilities(OnTriggeredAbilities, InAbilitySystemToGive, ApplyLevel);
}

void UDataAsset_StartUpBase::GrantAbilities(const TArray<TSubclassOf<URogueTowerGameplayAbility>>& InAbilityToGive, URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel)
{
	if (InAbilityToGive.IsEmpty()) { return; }

	for (const TSubclassOf<URogueTowerGameplayAbility>& Ability : InAbilityToGive)
	{
		if (!Ability) { continue; }

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InAbilitySystemToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InAbilitySystemToGive->GiveAbility(AbilitySpec);
	}
}

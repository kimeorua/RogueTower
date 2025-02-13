// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpPlayer.h"
#include "GAS/Ability/RogueTowerPlayerGameplayAbility.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"

void UDataAsset_StartUpPlayer::GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InAbilitySystemToGive, ApplyLevel);

	for (const FPlayerAbilitySet& AbilitiySet : PlayerStartUpAbilities)
	{
		if (!AbilitiySet.IsVaild()) { continue; }

		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilitiySet.AbilityToGrant);
		AbilitySpec.SourceObject = InAbilitySystemToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitiySet.InputTag);

		InAbilitySystemToGive->GiveAbility(AbilitySpec);
	}
}

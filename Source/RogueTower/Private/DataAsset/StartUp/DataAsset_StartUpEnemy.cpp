// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpEnemy.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "GAS/Ability/RogueTowerEnemyGameplayAbility.h"

void UDataAsset_StartUpEnemy::GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InAbilitySystemToGive, ApplyLevel);
	GiveEnemyAbilities(ActivateOnceEnemyAbilities, InAbilitySystemToGive, ApplyLevel);
	GiveEnemyAbilities(EnemyAbilities, InAbilitySystemToGive, ApplyLevel);

	if (!(StartUpGameplayEffects.IsEmpty()))
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass) { continue; }
			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InAbilitySystemToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InAbilitySystemToGive->MakeEffectContext());
		}
	}
}

void UDataAsset_StartUpEnemy::GiveEnemyAbilities(TArray<TSubclassOf<URogueTowerEnemyGameplayAbility>> InGiveAbilities, URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel)
{
	for (TSubclassOf<URogueTowerEnemyGameplayAbility> OnGiveEnemyAbility : InGiveAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(OnGiveEnemyAbility);
		AbilitySpec.SourceObject = InAbilitySystemToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InAbilitySystemToGive->GiveAbility(AbilitySpec);
	}
}
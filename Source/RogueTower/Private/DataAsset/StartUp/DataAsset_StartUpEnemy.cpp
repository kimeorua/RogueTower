// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/StartUp/DataAsset_StartUpEnemy.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"

void UDataAsset_StartUpEnemy::GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InAbilitySystemToGive, ApplyLevel);

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
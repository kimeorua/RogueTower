// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/RogueTowerGameplayAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Component/Combet/PawnCombetComponent.h"
#include "Character/RogueTowerBaseCharacter.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"

void URogueTowerGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void URogueTowerGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (AbilityActivationPolicy == EAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombetComponent* URogueTowerGameplayAbility::GetPawnCombetComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombetComponent>();
}

URogueTowerAbilitySystemComponent* URogueTowerGameplayAbility::GetRogueTowerAbilitySystemComponentFromActorInfo() const
{
	return Cast<URogueTowerAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

ARogueTowerBaseCharacter* URogueTowerGameplayAbility::GetRogueTowerBaseCharacterFromActorInfo() const
{
	ARogueTowerBaseCharacter* BaseCharacter = Cast<ARogueTowerBaseCharacter>(GetAvatarActorFromActorInfo());
	return IsValid(BaseCharacter) ? BaseCharacter : nullptr;
}

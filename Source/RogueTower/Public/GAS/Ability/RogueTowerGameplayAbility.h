// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RogueTowerGameplayAbility.generated.h"

class URogueTowerAbilitySystemComponent;
class UPawnCombetComponent;


UENUM(BlueprintType)
enum class EAbilityActivationPolicy : uint8
{
	OnTriggered, 
	OnGiven 
};

UCLASS()
class ROGUETOWER_API URogueTowerGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "Rogue Tower Ability")
	EAbilityActivationPolicy AbilityActivationPolicy = EAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Rogue Tower Ability")
	UPawnCombetComponent* GetPawnCombetComponentFromActorInfo()const;

	UFUNCTION(BlueprintPure, Category = "Rogue Tower Ability")
	URogueTowerAbilitySystemComponent* GetRogueTowerAbilitySystemComponentFromActorInfo() const;
	
};

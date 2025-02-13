// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpBase.generated.h"

class URogueTowerAbilitySystemComponent;
class URogueTowerGameplayAbility;

UCLASS()
class ROGUETOWER_API UDataAsset_StartUpBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<URogueTowerGameplayAbility>> OnTriggeredAbilities;

	void GrantAbilities(const TArray< TSubclassOf<URogueTowerGameplayAbility >>& InAbilityToGive, URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel = 1);

};

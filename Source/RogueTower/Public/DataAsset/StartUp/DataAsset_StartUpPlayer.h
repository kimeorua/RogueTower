// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "RogueTowerTypes/RogueTowerStructTypes.h"
#include "DataAsset_StartUpPlayer.generated.h"

class URogueTowerAbilitySystemComponent;


UCLASS()
class ROGUETOWER_API UDataAsset_StartUpPlayer : public UDataAsset_StartUpBase
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(URogueTowerAbilitySystemComponent* InAbilitySystemToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FPlayerAbilitySet> PlayerStartUpAbilities;

};

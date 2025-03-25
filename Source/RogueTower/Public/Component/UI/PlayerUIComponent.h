// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/PawnUIComponent.h"
#include "PlayerUIComponent.generated.h"

class ARogueTowerPlayerCharacter;
class URogueTowerWidgetBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponIconChangedDelegate, TSoftObjectPtr<UTexture2D>, WeaponIcon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHPChangedDelegate, float, NewMaxHP);

UCLASS()
class ROGUETOWER_API UPlayerUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FOnPecentChangedDelegate OnCurrentSPChanged;

	UPROPERTY(BlueprintAssignable)
	FOnWeaponIconChangedDelegate OnWeaponIconChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxHPChangedDelegate OnMaxHPChanged;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URogueTowerWidgetBase>StatusUpUIClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URogueTowerWidgetBase>GameClearUIClass;

	void CreateStatusUpUI();

	void CreateClrearUI();
};
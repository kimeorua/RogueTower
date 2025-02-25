// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/PawnUIComponent.h"
#include "PlayerUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponIconChangedDelegate, TSoftObjectPtr<UTexture2D>, WeaponIcon);

UCLASS()
class ROGUETOWER_API UPlayerUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FOnPecentChangedDelegate OnCurrentSPChanged;

	UPROPERTY(BlueprintAssignable)
	FOnWeaponIconChangedDelegate OnWeaponIconChanged;
};
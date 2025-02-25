// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RogueTowerWidgetBase.generated.h"

class UPlayerCombetComponent;
class UPlayerUIComponent;
class UEnemyUIComponent;
/**
 * 
 */
UCLASS()
class ROGUETOWER_API URogueTowerWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Player Combet Component Initalized"))
	void BP_OnOwningPlayerCombetComponentInitalized(UPlayerCombetComponent* OwningPlayerCombetComponent);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Player UI Component Initalized"))
	void BP_OnOwningPlayerUIComponentInitalized(UPlayerUIComponent* OwningPlayerUIComponent);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Enemy UI Component Initalized"))
	void BP_OnOwningEnemyUIComponentInitalized(UEnemyUIComponent* OwningEnemyUIComponent);

public:
	UFUNCTION(BlueprintCallable)
	void InitEnemyCharacterWidget(AActor* OwningEnemyActor);

};
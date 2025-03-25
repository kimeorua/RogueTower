// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UI/PlayerUIComponent.h"
#include "UI/RogueTowerWidgetBase.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTypes/RogueTowerEnums.h"

void UPlayerUIComponent::CreateStatusUpUI()
{
	URogueTowerWidgetBase* StatusUpUI = CreateWidget<URogueTowerWidgetBase>(GetWorld()->GetFirstPlayerController(), StatusUpUIClass);

	if (StatusUpUI)
	{
		StatusUpUI->AddToViewport();
	}
}

void UPlayerUIComponent::CreateClrearUI()
{
	URogueTowerWidgetBase* ClearUI = CreateWidget<URogueTowerWidgetBase>(GetWorld()->GetFirstPlayerController(), GameClearUIClass);

	if (ClearUI)
	{
		ClearUI->AddToViewport();
		URogueTowerFunctionLibrary::ToggleInputMode(this, ERogueTowerInputMode::UIOnly);
	}
}
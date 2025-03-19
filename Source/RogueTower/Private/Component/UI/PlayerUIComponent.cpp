// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UI/PlayerUIComponent.h"
#include "UI/RogueTowerWidgetBase.h"
#include "Character/RogueTowerPlayerCharacter.h"

void UPlayerUIComponent::CreateStatusUpUI()
{
	URogueTowerWidgetBase* StatusUpUI = CreateWidget<URogueTowerWidgetBase>(GetWorld()->GetFirstPlayerController(), StatusUpUIClass);

	if (StatusUpUI)
	{
		StatusUpUI->AddToViewport();
	}
}
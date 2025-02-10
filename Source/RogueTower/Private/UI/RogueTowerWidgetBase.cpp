// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RogueTowerWidgetBase.h"
#include "Interface/PawnCombetInterface.h"

void URogueTowerWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnCombetInterface* PawnCombetInterface = Cast<IPawnCombetInterface>(GetOwningPlayerPawn()))
	{
		if (UPlayerCombetComponent* PlayerCombetComponent = PawnCombetInterface->GetPlayerCombetComponent())
		{
			BP_OnOwningPlayerCombetComponentInitalized(PlayerCombetComponent);
		}
	}
}

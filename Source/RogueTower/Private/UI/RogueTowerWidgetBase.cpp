// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RogueTowerWidgetBase.h"
#include "Interface/PawnCombetInterface.h"
#include "Interface/PawnUIInterface.h"

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

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UPlayerUIComponent* PlayerUIComponent = PawnUIInterface->GetPlayerUIComponent())
		{
			BP_OnOwningPlayerUIComponentInitalized(PlayerUIComponent);
		}
	}
}

void URogueTowerWidgetBase::InitEnemyCharacterWidget(AActor* OwningEnemyActor)
{
	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwningEnemyActor))
	{
		if (UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent())
		{
			checkf(EnemyUIComponent, TEXT("Faild to extrac an EnemyUIComponent from %s"), * OwningEnemyActor->GetActorNameOrLabel());

			BP_OnOwningEnemyUIComponentInitalized(EnemyUIComponent);
		}
	}
}

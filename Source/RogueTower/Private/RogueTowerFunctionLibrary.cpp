// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueTowerFunctionLibrary.h"
#include "Engine/Engine.h"


void URogueTowerFunctionLibrary::ToggleInputMode(const UObject* WorldContextObject, ERogueTowerInputMode InInputMode)
{
	APlayerController* PlayerController = nullptr;
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (World)
		{
			PlayerController = World->GetFirstPlayerController();
		}
	}
	if (!PlayerController) { return; }

	FInputModeGameOnly GameOnlyMode;
	FInputModeUIOnly UIOnly;

	switch (InInputMode)
	{

	case ERogueTowerInputMode::GameOnly:
		PlayerController->SetInputMode(GameOnlyMode);
		PlayerController->bShowMouseCursor = false;

		break;
	case ERogueTowerInputMode::UIOnly:
		PlayerController->SetInputMode(UIOnly);
		PlayerController->bShowMouseCursor = true;
		break;
	default:
		break;
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueTowerFunctionLibrary.h"
#include "Engine/Engine.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "Interface/PawnCombetInterface.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "RogueTowerTags.h"


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

URogueTowerAbilitySystemComponent* URogueTowerFunctionLibrary::NativeGetRogueTowerAbilitySystemFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<URogueTowerAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	URogueTowerAbilitySystemComponent* ASC = NativeGetRogueTowerAbilitySystemFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(TagToAdd)) 
	{
		ASC->AddLooseGameplayTag(TagToAdd); 
	}
}

void URogueTowerFunctionLibrary::RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove)
{
	URogueTowerAbilitySystemComponent* ASC = NativeGetRogueTowerAbilitySystemFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool URogueTowerFunctionLibrary::NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	URogueTowerAbilitySystemComponent* ASC = NativeGetRogueTowerAbilitySystemFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void URogueTowerFunctionLibrary::BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ERogueTowerConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoseActorHaveTag(InActor, TagToCheck) ? ERogueTowerConfirmType::Yes : ERogueTowerConfirmType::No;
}

UPawnCombetComponent* URogueTowerFunctionLibrary::NativeGetPawnCombetComponentFromActor(AActor* InActor)
{
	if (IPawnCombetInterface* PawnCombetInterface = Cast<IPawnCombetInterface>(InActor))
	{
		return PawnCombetInterface->GetPawnCombetComponent();
	}
	return nullptr;
}

UPawnCombetComponent* URogueTowerFunctionLibrary::BP_GetPawnCombetComponentFromActor(AActor* InActor, ERogueTowerVaildType& OutVaildType)
{
	UPawnCombetComponent* CombetComponent = NativeGetPawnCombetComponentFromActor(InActor);
	OutVaildType = CombetComponent ? ERogueTowerVaildType::Vaild : ERogueTowerVaildType::Invaild;
	return CombetComponent;
}

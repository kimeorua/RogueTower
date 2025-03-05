// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "RogueTowerFunctionLibrary.generated.h"

class URogueTowerAbilitySystemComponent;
class UPawnCombetComponent;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API URogueTowerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "RogueTower | Function Library", meta = (WorldContext = "WorldContextObject"))
	static void ToggleInputMode(const UObject* WorldContextObject, ERogueTowerInputMode InInputMode);

	static URogueTowerAbilitySystemComponent* NativeGetRogueTowerAbilitySystemFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "RogueTower | Function Library")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "RogueTower | Function Library")
	static void RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "RogueTower | Function Library", meta = (DisplayName = "Dose Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ERogueTowerConfirmType& OutConfirmType);

	static UPawnCombetComponent* NativeGetPawnCombetComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "RogueTower | Function Library", meta = (DisplayName = "Get Pawn Combet Component From Actor", ExpandEnumAsExecs = "OutVaildType"))
	static UPawnCombetComponent* BP_GetPawnCombetComponentFromActor(AActor* InActor, ERogueTowerVaildType& OutVaildType);

	UFUNCTION(BlueprintCallable, Category = "RogueTower | Function Library")
	static bool IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "RogueTowerFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ROGUETOWER_API URogueTowerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "RogueTower|Function Library", meta = (WorldContext = "WorldContextObject"))
	static void ToggleInputMode(const UObject* WorldContextObject, ERogueTowerInputMode InInputMode);
};

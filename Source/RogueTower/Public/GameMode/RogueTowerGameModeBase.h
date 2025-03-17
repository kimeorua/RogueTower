// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RogueTowerGameModeBase.generated.h"

class AStageManager;

UCLASS()
class ROGUETOWER_API ARogueTowerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure)
	AStageManager* GetStageManager() const;
};

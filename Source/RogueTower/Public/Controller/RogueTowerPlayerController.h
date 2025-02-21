// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "RogueTowerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ROGUETOWER_API ARogueTowerPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:
	ARogueTowerPlayerController();

	//~Begine IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~End IGenericTeamAgentInterface
private:
	FGenericTeamId PlayerTeamID;
};

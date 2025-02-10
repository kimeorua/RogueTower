// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/PawnCombetInterface.h"
#include "RogueTowerBaseCharacter.generated.h"

UCLASS()
class ROGUETOWER_API ARogueTowerBaseCharacter : public ACharacter, public IPawnCombetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARogueTowerBaseCharacter();

	virtual UPawnCombetComponent* GetPawnCombetComponent() const override;
};

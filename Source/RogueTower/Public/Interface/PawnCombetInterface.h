// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnCombetInterface.generated.h"

class UPawnCombetComponent;
class UPlayerCombetComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnCombetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ROGUETOWER_API IPawnCombetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UPawnCombetComponent* GetPawnCombetComponent() const = 0;

	virtual UPlayerCombetComponent* GetPlayerCombetComponent() const { return nullptr; }
};

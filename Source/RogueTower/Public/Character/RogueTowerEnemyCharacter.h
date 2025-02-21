// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RogueTowerBaseCharacter.h"
#include "RogueTowerEnemyCharacter.generated.h"

class UEnemyCombetComponent;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API ARogueTowerEnemyCharacter : public ARogueTowerBaseCharacter
{
	GENERATED_BODY()
	
public:
	ARogueTowerEnemyCharacter();

	virtual UPawnCombetComponent* GetPawnCombetComponent() const override;

protected:
	virtual void BeginPlay() override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combet")
	UEnemyCombetComponent* EnemyCombetComponent;

public:
	FORCEINLINE UEnemyCombetComponent* GetEnemyCombetComponent() const { return EnemyCombetComponent; }
};

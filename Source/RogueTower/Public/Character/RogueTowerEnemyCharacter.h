// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RogueTowerBaseCharacter.h"
#include "RogueTowerEnemyCharacter.generated.h"

class UEnemyCombetComponent;
class UEnemyUIComponent;
class UWidgetComponent;

/**
 * 
 */
UCLASS()
class ROGUETOWER_API ARogueTowerEnemyCharacter : public ARogueTowerBaseCharacter
{
	GENERATED_BODY()
	
public:
	ARogueTowerEnemyCharacter();

	// ~Begin IPawnCombetInterface
	virtual UPawnCombetComponent* GetPawnCombetComponent() const override;
	// ~End IPawnCombetInterface

	// ~Begin IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UEnemyUIComponent* GetEnemyUIComponent() const override;
	// ~End IPawnUIInterface

protected:
	virtual void BeginPlay() override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combet")
	UEnemyCombetComponent* EnemyCombetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	UEnemyUIComponent* EnemyUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* EnemyHPBarWidgetComponent;

public:
	FORCEINLINE UEnemyCombetComponent* GetEnemyCombetComponent() const { return EnemyCombetComponent; }
};

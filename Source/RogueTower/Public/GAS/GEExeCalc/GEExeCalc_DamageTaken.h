// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExeCalc_DamageTaken.generated.h"

UCLASS()
class ROGUETOWER_API UGEExeCalc_DamageTaken : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UGEExeCalc_DamageTaken();

	// ~Begin UGameplayEffectExecutionCalculation
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	// ~End UGameplayEffectExecutionCalculation
};
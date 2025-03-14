// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExeCalc_SPCharge.generated.h"

/**
 * 
 */
UCLASS()
class ROGUETOWER_API UGEExeCalc_SPCharge : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UGEExeCalc_SPCharge();

	// ~Begin UGameplayEffectExecutionCalculation
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	// ~End UGameplayEffectExecutionCalculation
};

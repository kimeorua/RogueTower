// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GEExeCalc/GEExeCalc_SPCharge.h"
#include "GAS/RogueTowerAttributeSet.h"

struct FRogueTowerSPChargeCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(ATK);
	DECLARE_ATTRIBUTE_CAPTUREDEF(CurrentSP);
	DECLARE_ATTRIBUTE_CAPTUREDEF(WeaponBaseDamage);

	FRogueTowerSPChargeCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, ATK, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, WeaponBaseDamage, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, CurrentSP, Source, false);
	}
};

static const FRogueTowerSPChargeCapture& GetRogueTowerSPChargeCapture()
{
	static FRogueTowerSPChargeCapture RogueTowerSPChargeCapture;

	return RogueTowerSPChargeCapture;
}
UGEExeCalc_SPCharge::UGEExeCalc_SPCharge()
{
	RelevantAttributesToCapture.Add(GetRogueTowerSPChargeCapture().ATKDef);
	RelevantAttributesToCapture.Add(GetRogueTowerSPChargeCapture().WeaponBaseDamageDef);
	RelevantAttributesToCapture.Add(GetRogueTowerSPChargeCapture().CurrentSPDef);
}

void UGEExeCalc_SPCharge::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceATK = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetRogueTowerSPChargeCapture().ATKDef, EvaluateParameters, SourceATK);

	float SourceWeaponBaseDamage = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetRogueTowerSPChargeCapture().WeaponBaseDamageDef, EvaluateParameters, SourceWeaponBaseDamage);

	float const SPCharge = SourceWeaponBaseDamage * SourceATK;

	if (SPCharge > 0)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(GetRogueTowerSPChargeCapture().CurrentSPProperty, EGameplayModOp::Additive, SPCharge));
	}
}
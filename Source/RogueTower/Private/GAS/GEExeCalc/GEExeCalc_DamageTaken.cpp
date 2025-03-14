// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GEExeCalc/GEExeCalc_DamageTaken.h"
#include "GAS/RogueTowerAttributeSet.h"

struct FRogueTowerDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(ATK);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DEF);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);
	DECLARE_ATTRIBUTE_CAPTUREDEF(WeaponBaseDamage);

	FRogueTowerDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, ATK, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, WeaponBaseDamage, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, DEF, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(URogueTowerAttributeSet, Damage, Target, false);
	}
};

static const FRogueTowerDamageCapture& GetRogueTowerDamageCapture()
{
	static FRogueTowerDamageCapture RogueTowerDamageCapture;

	return RogueTowerDamageCapture;
}

UGEExeCalc_DamageTaken::UGEExeCalc_DamageTaken()
{
	RelevantAttributesToCapture.Add(GetRogueTowerDamageCapture().ATKDef);
	RelevantAttributesToCapture.Add(GetRogueTowerDamageCapture().WeaponBaseDamageDef);
	RelevantAttributesToCapture.Add(GetRogueTowerDamageCapture().DEFDef);
	RelevantAttributesToCapture.Add(GetRogueTowerDamageCapture().DamageDef);
}

void UGEExeCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceATK = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetRogueTowerDamageCapture().ATKDef, EvaluateParameters, SourceATK);

	float SourceWeaponBaseDamage = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetRogueTowerDamageCapture().WeaponBaseDamageDef, EvaluateParameters, SourceWeaponBaseDamage);

	float TargetDEF = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetRogueTowerDamageCapture().DEFDef, EvaluateParameters, TargetDEF);

	float const FinalDamage = (SourceWeaponBaseDamage * SourceATK) - TargetDEF;
	if (FinalDamage > 0)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(GetRogueTowerDamageCapture().DamageProperty, EGameplayModOp::Override, FinalDamage));
	}
}
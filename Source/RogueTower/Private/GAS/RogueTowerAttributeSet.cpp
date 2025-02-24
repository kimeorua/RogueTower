// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RogueTowerAttributeSet.h"

URogueTowerAttributeSet::URogueTowerAttributeSet()
{
	InitCurrentHP(1.0f);
	InitMaxHP(1.0f);

	InitCurrentSP(1.0f);
	InitMaxSP(1.0f);

	InitATK(1.0f);
	InitDEF(1.0f);
	InitATTSPD(1.0f);
}

void URogueTowerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	// TODO : PostGameplayEffectExecute 구현
	// TODO: Attribute 값 변경시 실시
}

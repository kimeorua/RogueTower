// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RogueTowerAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Interface/PawnUIInterface.h"
#include "Component/UI/PawnUIComponent.h"
#include "Component/UI/PlayerUIComponent.h"
#include "RogueTowerTags.h"
#include "RogueTowerFunctionLibrary.h"

URogueTowerAttributeSet::URogueTowerAttributeSet()
{
	InitCurrentHP(1.0f);
	InitMaxHP(1.0f);

	InitCurrentSP(1.0f);
	InitMaxSP(1.0f);

	InitATK(1.0f);
	InitDEF(1.0f);
	InitATTSPD(1.0f);
	InitAvoidStrenght(1.0f);

	InitDamage(0.0f);
	InitWeaponBaseDamage(0.0f);
}

void URogueTowerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!ChacedPawnUIInterface.IsValid())
	{
		ChacedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	checkf(ChacedPawnUIInterface.IsValid(), TEXT("%s didn't implement IPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	UPawnUIComponent* PawnUIComponent = ChacedPawnUIInterface->GetPawnUIComponent();

	checkf(PawnUIComponent, TEXT("Couldn't extrac a PawnUIComponent from %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	if (Data.EvaluatedData.Attribute == GetCurrentHPAttribute())
	{
		const float NewCurrentHP = FMath::Clamp(GetCurrentHP(), 0.0f, GetMaxHP());
		SetCurrentHP(NewCurrentHP);
		PawnUIComponent->OnCurrentHPChanged.Broadcast(GetCurrentHP() / GetMaxHP());
	}
	if (Data.EvaluatedData.Attribute == GetMaxHPAttribute())
	{
		const float NewMaxHP = FMath::Clamp(GetMaxHP(), GetCurrentHP(), 200.0f);
		SetMaxHP(NewMaxHP);

		if (UPlayerUIComponent* PlayerUIComponent = ChacedPawnUIInterface->GetPlayerUIComponent())
		{
			PlayerUIComponent->OnMaxHPChanged.Broadcast(GetMaxHP());
		}	
	}
	if (Data.EvaluatedData.Attribute == GetCurrentSPAttribute())
	{
		const float NewCurrentSP = FMath::Clamp(GetCurrentSP(), 0.0f, GetMaxSP());
		SetCurrentSP(NewCurrentSP);

		if (UPlayerUIComponent* PlayerUIComponent = ChacedPawnUIInterface->GetPlayerUIComponent())
		{
			PlayerUIComponent->OnCurrentSPChanged.Broadcast(GetCurrentSP() / GetMaxSP());
		}
	}

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		const float OldHealth = GetCurrentHP();
		const float DamageDone = GetDamage();

		const float NewCurentHP = FMath::Clamp(OldHealth - DamageDone, 0.0f, GetMaxHP());

		SetCurrentHP(NewCurentHP);

		PawnUIComponent->OnCurrentHPChanged.Broadcast(GetCurrentHP() / GetMaxHP());

		if (GetCurrentHP() == 0.0f)
		{
			URogueTowerFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), RogueTowerTag::Shared_Status_Death);
		}
	}

	if (Data.EvaluatedData.Attribute == GetATKAttribute())
	{
		// TODO : 공격 배율 증감 시 작동
	}
	if (Data.EvaluatedData.Attribute == GetDEFAttribute())
	{
		// TODO : 방어도 증감 시 작동
	}
	if (Data.EvaluatedData.Attribute == GetATTSPDAttribute())
	{
		// TODO: 공속 증감 시 작동
	}
	if (Data.EvaluatedData.Attribute == GetAvoidStrenghtAttribute())
	{
		// TODO: 회피거리 증감 시 작동
	}
}
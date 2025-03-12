// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PawnCombetComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "RogueTowerTags.h"
#include "RogueTowerFunctionLibrary.h"

UPawnCombetComponent::UPawnCombetComponent()
{

}

void UPawnCombetComponent::CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate)
{
}

void UPawnCombetComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlapedActors.Contains(HitActor)) { return; }

	OverlapedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;


	if (URogueTowerFunctionLibrary::NativeDoseActorHaveTag(HitActor, RogueTowerTag::Player_Status_Avoid))
	{
		return;
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), RogueTowerTag::Shared_Event_MeleeHit, Data);
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, RogueTowerTag::Shared_Event_HitReact, FGameplayEventData());
	}
}
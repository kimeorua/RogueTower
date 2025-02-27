// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/PawnCombetComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "RogueTowerTags.h"
#include "DebugHelper.h"

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

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), RogueTowerTag::Shared_Event_MeleeHit, Data);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/RogueTowerEnemyGameplayAbility.h"
#include "Character/RogueTowerEnemyCharacter.h"
#include "Component/Combet/EnemyCombetComponent.h"
#include "Controller/EnemyAIController.h"

ARogueTowerEnemyCharacter* URogueTowerEnemyGameplayAbility::GetRogueTowerEnemyCharacterFromActorInfo()
{
	if (!CachedRogueTowerEnemyCharacter.IsValid())
	{
		CachedRogueTowerEnemyCharacter = Cast<ARogueTowerEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedRogueTowerEnemyCharacter.IsValid() ? CachedRogueTowerEnemyCharacter.Get() : nullptr;
}

UEnemyCombetComponent* URogueTowerEnemyGameplayAbility::GetEnemyCombetComponentFromActorInfo()
{
	return GetRogueTowerEnemyCharacterFromActorInfo()->GetEnemyCombetComponent();
}

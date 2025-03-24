// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTT_ActivateAbility.h"
#include "Character/RogueTowerEnemyCharacter.h"
#include "Controller/EnemyAIController.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "RogueTowerFunctionLibrary.h"
#include "RogueTowerTags.h"

UBTT_ActivateAbility::UBTT_ActivateAbility()
{
	NodeName = "Activte Ability";
	bNotifyTick = true; 
	bNotifyTaskFinished = true;
}

EBTNodeResult::Type UBTT_ActivateAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ARogueTowerEnemyCharacter* Enemy = Cast<ARogueTowerEnemyCharacter>(OwnerComp.GetAIOwner()->GetCharacter());

	if (IsValid(Enemy) && IsValid(Enemy->GetAbilitySystemComponent()))
	{
		FGameplayTagContainer TagContainer;
		TagContainer.AddTag(Tag);

		Enemy->GetAbilitySystemComponent()->TryActivateAbilitiesByTag(TagContainer);
		return EBTNodeResult::InProgress;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}

void UBTT_ActivateAbility::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	AEnemyAIController* AI = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (AbilityEnd(OwnerComp.GetAIOwner()->GetCharacter()))
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}
}

bool UBTT_ActivateAbility::AbilityEnd(AActor* Owner)
{
	return URogueTowerFunctionLibrary::NativeDoseActorHaveTag(Owner, RogueTowerTag::Enemy_Status_ActivateAbility) ? false : true;
}
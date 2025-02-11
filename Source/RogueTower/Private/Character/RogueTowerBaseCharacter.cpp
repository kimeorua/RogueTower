// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RogueTowerBaseCharacter.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "GAS/RogueTowerAttributeSet.h"

// Sets default values
ARogueTowerBaseCharacter::ARogueTowerBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false; 
	
	GetMesh()->bReceivesDecals = false;

	RogueTowerAbilitySystemComponent = CreateDefaultSubobject<URogueTowerAbilitySystemComponent>(TEXT("WrriorAbilitySystemComponent"));
	RogueTowerAttributeSet = CreateDefaultSubobject<URogueTowerAttributeSet>(TEXT("WrriorAttributeSet"));
}

UPawnCombetComponent* ARogueTowerBaseCharacter::GetPawnCombetComponent() const
{
	return nullptr;
}

UAbilitySystemComponent* ARogueTowerBaseCharacter::GetAbilitySystemComponent() const
{
	return GetRogueTowerAbilitySystemComponent();
}

void ARogueTowerBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (RogueTowerAbilitySystemComponent)
	{
		RogueTowerAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

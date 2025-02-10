// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RogueTowerBaseCharacter.h"

// Sets default values
ARogueTowerBaseCharacter::ARogueTowerBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false; 
	
	GetMesh()->bReceivesDecals = false;
}

UPawnCombetComponent* ARogueTowerBaseCharacter::GetPawnCombetComponent() const
{
	return nullptr;
}

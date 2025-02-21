// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RogueTowerEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Component/Combet/EnemyCombetComponent.h"

ARogueTowerEnemyCharacter::ARogueTowerEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 180.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.0f;

	EnemyCombetComponent = CreateDefaultSubobject<UEnemyCombetComponent>(TEXT("EnemyCombetComponent"));
}

UPawnCombetComponent* ARogueTowerEnemyCharacter::GetPawnCombetComponent() const
{
	return EnemyCombetComponent;
}

void ARogueTowerEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueTowerEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

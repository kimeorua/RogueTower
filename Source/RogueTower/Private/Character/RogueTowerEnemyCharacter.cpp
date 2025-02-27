// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RogueTowerEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Component/Combet/EnemyCombetComponent.h"
#include "DataAsset/StartUp/DataAsset_StartUpEnemy.h"
#include "Component/UI/EnemyUIComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/RogueTowerWidgetBase.h"

#include "DebugHelper.h"
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
	EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>(TEXT("EnemyUIComponent"));
	EnemyHPBarWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyHPBarWidgetComponent"));
	EnemyHPBarWidgetComponent->SetupAttachment(GetMesh());
}

UPawnCombetComponent* ARogueTowerEnemyCharacter::GetPawnCombetComponent() const
{
	return EnemyCombetComponent;
}

UPawnUIComponent* ARogueTowerEnemyCharacter::GetPawnUIComponent() const
{
	return EnemyUIComponent;
}

UEnemyUIComponent* ARogueTowerEnemyCharacter::GetEnemyUIComponent() const
{
	return EnemyUIComponent;
}

void ARogueTowerEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (URogueTowerWidgetBase* HPBarWidget = Cast<URogueTowerWidgetBase>(EnemyHPBarWidgetComponent->GetUserWidgetObject()))
	{
		HPBarWidget->InitEnemyCharacterWidget(this);
	}

	if (!StartUpData.IsNull())
	{
		if (UDataAsset_StartUpBase* LoadData = StartUpData.LoadSynchronous())
		{
			LoadData->GiveToAbilitySystemComponent(RogueTowerAbilitySystemComponent);
		}
	}
}

void ARogueTowerEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Stage/StageManager.h"
#include "Kismet/GameplayStatics.h"
#include "Stage/EnemySpawner.h"

#include "DebugHelper.h"

AStageManager* AStageManager::Instance = nullptr;

// Sets default values
AStageManager::AStageManager()
{
	PrimaryActorTick.bCanEverTick = false;

    OnSpawnStart.AddDynamic(this, &ThisClass::EnemySpawn);
    OnEnemyDied.AddDynamic(this, &ThisClass::ClearCurrentStage);
}

AStageManager* AStageManager::Get(UWorld* World)
{
    if (Instance == nullptr)
    {
        TArray<AActor*> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(World, AStageManager::StaticClass(), FoundActors);

        if (FoundActors.Num() > 0)
        {
            Instance = Cast<AStageManager>(FoundActors[0]);
        }
    }
    return Instance;
}

void AStageManager::EnemyCountChange(bool IsAdd)
{
    if (IsAdd)
    {
        CurrentEnemyCount++;
    }
    else
    {
        CurrentEnemyCount--;

        if (CurrentEnemyCount < 0)
        {
            CurrentEnemyCount = 0;
        }
    }
}

// Called when the game starts or when spawned
void AStageManager::BeginPlay()
{
	Super::BeginPlay();

    if (Instance == nullptr)
    {
        Instance = this;
    }
}

void AStageManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    if (Instance == this)
    {
        Instance = nullptr;
    }
}

void AStageManager::EnemySpawn()
{
    if (EnemySpawner)
    {
        EnemySpawner->EnemySpawnerActivate(CurrentStage);
    }
}

void AStageManager::ClearCurrentStage()
{
    Debug::Print(TEXT("Enemy Is Died"));

    EnemyCountChange(false);

    Debug::Print(TEXT("Current Enemies : "), CurrentEnemyCount);

    if (CurrentEnemyCount == 0)
    {
        CurrentStage++;

        Debug::Print(TEXT("Current Stage : "), CurrentStage);
    }
}
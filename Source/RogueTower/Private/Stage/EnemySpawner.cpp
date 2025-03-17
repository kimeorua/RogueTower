// Fill out your copyright notice in the Description page of Project Settings.


#include "Stage/EnemySpawner.h"

#include "DebugHelper.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AEnemySpawner::EnemySpawnerActivate()
{
	Debug::Print(TEXT("EnemySpanwer Is Activate"));
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
}
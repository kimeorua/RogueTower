// Fill out your copyright notice in the Description page of Project Settings.


#include "Stage/EnemySpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Character/RogueTowerEnemyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "GameMode/RogueTowerGameModeBase.h"
#include "Stage/StageManager.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemySpawner::EnemySpawnerActivate(int32 StageNum)
{
	if (!Player) { Player = UGameplayStatics::GetActorOfClass(GetWorld(), ARogueTowerPlayerCharacter::StaticClass()); }
	if (!GameMode) { GameMode = Cast<ARogueTowerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld())); }

	for (const FEnemySpawnInfo& SpawnInfo : GetCurrentStageSpanwerTableRow(StageNum)->EnemySpawnerInfo)
	{
		if (!SpawnInfo.EnemyClass) { continue; }

		for (int i = 0; i < SpawnInfo.SpawnedEnemyNum; i++)
		{
			ARogueTowerEnemyCharacter* SpawnedEnemy = GetWorld()->SpawnActor<ARogueTowerEnemyCharacter>(SpawnInfo.EnemyClass);
			SpawnedEnemy->SetActorLocation(SpawnInfo.SpawnLocation[i]);
			FRotator Rot = UKismetMathLibrary::FindLookAtRotation(SpawnedEnemy->GetActorLocation(), Player->GetActorLocation());
			SpawnedEnemy->SetActorRotation(Rot);
			GameMode->GetStageManager()->EnemyCountChange(true);
		}
	}
}

FEnemySpawnInfoTableRaw* AEnemySpawner::GetCurrentStageSpanwerTableRow(int32 StageNum) const
{
	const FName RowName = FName(TEXT("Stage") + FString::FromInt(StageNum));
	FEnemySpawnInfoTableRaw* FoundRow = EnemySpawnerDataTable->FindRow<FEnemySpawnInfoTableRaw>(RowName, FString());

	if (!FoundRow) { return nullptr; }
	return FoundRow;
}
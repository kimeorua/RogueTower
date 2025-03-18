// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueTowerTypes/RogueTowerStructTypes.h"
#include "EnemySpawner.generated.h"

class ARogueTowerPlayerCharacter;
class ARogueTowerGameModeBase;

UCLASS()
class ROGUETOWER_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UFUNCTION()
	void EnemySpawnerActivate(int32 StageNum);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Enemy Spawner Info")
	UDataTable* EnemySpawnerDataTable = nullptr;

	FEnemySpawnInfoTableRaw* GetCurrentStageSpanwerTableRow(int32 StageNum) const;

private:
	UPROPERTY()
	AActor* Player = nullptr;
	UPROPERTY()
	ARogueTowerGameModeBase* GameMode = nullptr;
};
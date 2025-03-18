// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StageManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawnStartDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemyDiedDelegate);

class AEnemySpawner;

UCLASS()
class ROGUETOWER_API AStageManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStageManager();

	UFUNCTION(BlueprintPure)
	static AStageManager* Get(UWorld* World);

	UPROPERTY(BlueprintCallable)
	FOnSpawnStartDelegate OnSpawnStart;

	UPROPERTY(BlueprintCallable)
	FOnEnemyDiedDelegate OnEnemyDied;

	void EnemyCountChange(bool IsAdd);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;  

	int32 CurrentStage = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Manger")
	int32 MaxStage = 5;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Manger")
	AEnemySpawner* EnemySpawner = nullptr;

	int32 CurrentEnemyCount = 0;

private:
	static AStageManager* Instance;

	UFUNCTION()
	void EnemySpawn();

	UFUNCTION()
	void ClearCurrentStage();
};

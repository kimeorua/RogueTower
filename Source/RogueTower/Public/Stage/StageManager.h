// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StageManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawnStartDelegate);

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;  

	int32 CurrentStage = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Manger")
	int32 MaxStage = 5;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Manger")
	AEnemySpawner* EnemySpawner;

private:
	static AStageManager* Instance;

	UFUNCTION()
	void EnemySpawn();
};

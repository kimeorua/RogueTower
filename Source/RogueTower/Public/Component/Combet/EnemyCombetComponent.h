// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Combet/PawnCombetComponent.h"
#include "EnemyCombetComponent.generated.h"

class ARogueTowerEnemyWeapon;

UCLASS()
class ROGUETOWER_API UEnemyCombetComponent : public UPawnCombetComponent
{
	GENERATED_BODY()
	
private:
	ARogueTowerEnemyWeapon* EnemyWeapon;

public:
	UFUNCTION(BlueprintCallable)
	void RegisterEnemyWeapon(ARogueTowerEnemyWeapon* InEnemyWeapon);

	UFUNCTION(BlueprintPure)
	FORCEINLINE ARogueTowerEnemyWeapon* GetEnemyWeapon() const { return EnemyWeapon; }

	virtual void CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PawnExtensionComponentBase.h"
#include "RogueTowerTypes/RogueTowerEnums.h"
#include "PawnCombetComponent.generated.h"





/**
 * 
 */
UCLASS()
class ROGUETOWER_API UPawnCombetComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UPawnCombetComponent();

	UFUNCTION(BlueprintCallable)
	virtual void CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate);

	virtual void OnHitTargetActor(AActor* HitActor);

protected:
	TArray<AActor*>OverlapedActors;
};

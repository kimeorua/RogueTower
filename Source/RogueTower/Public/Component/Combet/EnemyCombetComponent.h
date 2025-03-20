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

protected:
	//index 0 = Start,  index 1 =  End
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Attack Trace")
	TArray<FName>TraceSocket_Left;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Attack Trace")
	TArray<FName>TraceSocket_Right;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Attack Trace")
	FVector TraceBoxSize = FVector(5000.f, 5000.f, 300.f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Attack Trace")
	TArray<TEnumAsByte<EObjectTypeQuery>> BoxtraceChannel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Attack Trace")
	bool ShowDegubShape = false;

public:
	UFUNCTION(BlueprintCallable)
	void RegisterEnemyWeapon(ARogueTowerEnemyWeapon* InEnemyWeapon);

	UFUNCTION(BlueprintPure)
	FORCEINLINE ARogueTowerEnemyWeapon* GetEnemyWeapon() const { return EnemyWeapon; }

	virtual void CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate) override;

	void AttackTraceCheck(TArray<FName> TraceSockets);
};

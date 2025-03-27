// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/RogueTowerItemBase.h"
#include "RogueTowerWeapon.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

DECLARE_DELEGATE_OneParam(FOnTargetInteractedDelegate, AActor*);

UCLASS()
class ROGUETOWER_API ARogueTowerWeapon : public ARogueTowerItemBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Collision", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* WeaponCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effect", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* TrailParticle;

public:
	ARogueTowerWeapon();

	FOnTargetInteractedDelegate OnWeaponHitTarget;

	FORCEINLINE UBoxComponent* GetWeaponCollision() const { return WeaponCollision; }

protected:
	UFUNCTION()
	virtual void OnCollisionBoxBegineOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

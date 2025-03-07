// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Ability/RogueTowerPlayerGameplayAbility.h"
#include "PlayerLockOnAbility.generated.h"

UCLASS()
class ROGUETOWER_API UPlayerLockOnAbility : public URogueTowerPlayerGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begine UGameplayAbility
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility

	UFUNCTION(BlueprintCallable)
	void LockOnTick(float DeltaTime);

private:
	void TryLockOnTarget();
	void GetLockOnAbleActor();
	void CancelLockOnAbility();
	void CleanUp();

	AActor* GetNearstActorFromLockOnAbleActors(const TArray<AActor*>& InLockOnAbleActors);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Target Lock", meta = (AllowPrivateAccess = "true"))
	float TraceDistance = 5000.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Target Lock", meta = (AllowPrivateAccess = "true"))
	FVector TraceBoxSize = FVector(5000.f, 5000.f, 300.f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Target Lock", meta = (AllowPrivateAccess = "true"))
	TArray<TEnumAsByte<EObjectTypeQuery>> BoxtraceChannel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Target Lock", meta = (AllowPrivateAccess = "true"))
	bool ShowDegubShape = false;

	UPROPERTY()
	TArray<AActor*>LockOnAbleActors;

	UPROPERTY()
	AActor* CurrenttLockOnActor = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Target Lock", meta = (AllowPrivateAccess = "true"))
	float RotationSpeed = 5.0f;
};
// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/PlayerLockOnAbility.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Controller/RogueTowerPlayerController.h"

#include "DebugHelper.h"

void UPlayerLockOnAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	TryLockOnTarget();

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UPlayerLockOnAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	CleanUp();

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UPlayerLockOnAbility::LockOnTick(float DeltaTime)
{
	if (!CurrenttLockOnActor)
	{
		CancelLockOnAbility();
		return;
	}
	const FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(GetRogueTowerPlayerCharacterFromActorInfo()->GetActorLocation(), CurrenttLockOnActor->GetActorLocation());
	
	const FRotator CurrentContrlloerRot = GetRogueTowerPlayerControllerFromActorInfo()->GetControlRotation();
	const FRotator TargetRot = FMath::RInterpTo(CurrentContrlloerRot, LookAtRot, DeltaTime, RotationSpeed);

	GetRogueTowerPlayerControllerFromActorInfo()->SetControlRotation(FRotator(TargetRot.Pitch, TargetRot.Yaw, 0.f));
	GetRogueTowerPlayerCharacterFromActorInfo()->SetActorRotation(FRotator(0.f, TargetRot.Yaw, 0.f));
}

void UPlayerLockOnAbility::TryLockOnTarget()
{
	GetLockOnAbleActor();

	if (LockOnAbleActors.IsEmpty())
	{
		CancelLockOnAbility();
		return;
	}
	CurrenttLockOnActor = GetNearstActorFromLockOnAbleActors(LockOnAbleActors);
}

void UPlayerLockOnAbility::GetLockOnAbleActor()
{
	TArray<FHitResult> BoxTraceHits;

	UKismetSystemLibrary::BoxTraceMultiForObjects
	(
		GetRogueTowerPlayerCharacterFromActorInfo(),
		GetRogueTowerPlayerCharacterFromActorInfo()->GetActorLocation(),
		GetRogueTowerPlayerCharacterFromActorInfo()->GetActorLocation() + GetRogueTowerPlayerCharacterFromActorInfo()->GetActorForwardVector() * TraceDistance,
		TraceBoxSize / 2.f,
		GetRogueTowerPlayerCharacterFromActorInfo()->GetActorForwardVector().ToOrientationRotator(),
		BoxtraceChannel,
		false,
		TArray<AActor*>(),
		ShowDegubShape ? EDrawDebugTrace::Persistent : EDrawDebugTrace::None,
		BoxTraceHits,
		true
	);

	for (const FHitResult& TraceHit : BoxTraceHits)
	{
		if (AActor* HitActor = TraceHit.GetActor())
		{
			if (HitActor != GetRogueTowerPlayerCharacterFromActorInfo())
			{
				LockOnAbleActors.AddUnique(HitActor);
			}
		}
	}
}

void UPlayerLockOnAbility::CancelLockOnAbility()
{
	CancelAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true);
}

void UPlayerLockOnAbility::CleanUp()
{
	LockOnAbleActors.Empty(); 
	CurrenttLockOnActor = nullptr;
}

AActor* UPlayerLockOnAbility::GetNearstActorFromLockOnAbleActors(const TArray<AActor*>& InLockOnAbleActors)
{
	float ClosestDistance = 0.f;
	return UGameplayStatics::FindNearestActor(GetRogueTowerPlayerCharacterFromActorInfo()->GetActorLocation(), InLockOnAbleActors, ClosestDistance);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/PlayerLockOnAbility.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Character/RogueTowerPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Controller/RogueTowerPlayerController.h"
#include "UI/RogueTowerWidgetBase.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/SizeBox.h"

void UPlayerLockOnAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	TryLockOnTarget();

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UPlayerLockOnAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	GetRogueTowerPlayerCharacterFromActorInfo()->SettingLockOnSpringArmLocation(false);
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

	SetLockOnUIPostion();

	GetRogueTowerPlayerControllerFromActorInfo()->SetControlRotation(FRotator(TargetRot.Pitch, TargetRot.Yaw, 0.f));
	GetRogueTowerPlayerCharacterFromActorInfo()->SetActorRotation(FRotator(0.f, TargetRot.Yaw, 0.f));
}

void UPlayerLockOnAbility::TryLockOnTarget()
{
	GetLockOnAbleActor();

	if (LockOnAbleActors.IsEmpty())
	{
		CancelLockOnAbility();
		GetRogueTowerPlayerCharacterFromActorInfo()->SettingLockOnSpringArmLocation(false);
		return;
	}
	CurrenttLockOnActor = GetNearstActorFromLockOnAbleActors(LockOnAbleActors);

	if (CurrenttLockOnActor)
	{
		GetRogueTowerPlayerCharacterFromActorInfo()->SettingLockOnSpringArmLocation(true);
		DrawTargetLockOnUI();
		SetLockOnUIPostion();
	}
	else
	{
		CancelLockOnAbility();
		GetRogueTowerPlayerCharacterFromActorInfo()->SettingLockOnSpringArmLocation(false);
	}
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

void UPlayerLockOnAbility::DrawTargetLockOnUI()
{
	if (!LockOnUI)
	{
		LockOnUI = CreateWidget<URogueTowerWidgetBase>(GetRogueTowerPlayerControllerFromActorInfo(), TargetLockWidgetClass);
	} 
	LockOnUI->AddToViewport();
}

void UPlayerLockOnAbility::SetLockOnUIPostion()
{
	if (!LockOnUI || !CurrenttLockOnActor)
	{
		CancelLockOnAbility();
		return;
	}
	FVector2D ScreenPostion;

	UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition
	(
		GetRogueTowerPlayerControllerFromActorInfo(),
		CurrenttLockOnActor->GetActorLocation(),
		ScreenPostion,
		true
	);

	if (LockOnUISize == FVector2D::ZeroVector)
	{
		LockOnUI->WidgetTree->ForEachWidget
		(
			[this](UWidget* FoundWidget)
			{
				if (USizeBox* FoundSizeBox = Cast<USizeBox>(FoundWidget))
				{
					LockOnUISize.X = FoundSizeBox->GetWidthOverride();
					LockOnUISize.Y = FoundSizeBox->GetHeightOverride();
				}
			}
		);
	}
	ScreenPostion -= (LockOnUISize / 2.f);
	LockOnUI->SetPositionInViewport(ScreenPostion, false);
}

void UPlayerLockOnAbility::CancelLockOnAbility()
{
	CancelAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true);
}

void UPlayerLockOnAbility::CleanUp()
{
	LockOnAbleActors.Empty(); 
	CurrenttLockOnActor = nullptr;
	if (IsValid(LockOnUI))
	{
		LockOnUI->RemoveFromParent();
		//LockOnUI = nullptr;
	}
	LockOnUISize == FVector2D::ZeroVector;
}

AActor* UPlayerLockOnAbility::GetNearstActorFromLockOnAbleActors(const TArray<AActor*>& InLockOnAbleActors)
{
	float ClosestDistance = 0.f;
	return UGameplayStatics::FindNearestActor(GetRogueTowerPlayerCharacterFromActorInfo()->GetActorLocation(), InLockOnAbleActors, ClosestDistance);
}
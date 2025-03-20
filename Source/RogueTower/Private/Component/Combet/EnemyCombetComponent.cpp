// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/EnemyCombetComponent.h"
#include "Item/Weapon/RogueTowerEnemyWeapon.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Character/RogueTowerEnemyCharacter.h"

#include "DebugHelper.h"

void UEnemyCombetComponent::RegisterEnemyWeapon(ARogueTowerEnemyWeapon* InEnemyWeapon)
{
	if (!IsValid(InEnemyWeapon)) { return; }
	EnemyWeapon = InEnemyWeapon;
	EnemyWeapon->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
}

void UEnemyCombetComponent::CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate)
{
	if (Activate)
	{
		switch (Type)
		{
		case ERogueTowerCombetCollisionType::WeaponLeft :
			if (!IsValid(EnemyWeapon)) { return; }
			EnemyWeapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			break;

		case ERogueTowerCombetCollisionType::WeaponRight :
			if (!IsValid(EnemyWeapon)) { return; }
			break;

		case ERogueTowerCombetCollisionType::HandLeft: 
			AttackTraceCheck(TraceSocket_Left);
			break;

		case ERogueTowerCombetCollisionType::HandRight :
			AttackTraceCheck(TraceSocket_Right);
			break;

		default:
			break;
		}
	}
	else
	{
		if (!IsValid(EnemyWeapon)) { return; }
		EnemyWeapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OverlapedActors.Empty();
	}
}

void UEnemyCombetComponent::AttackTraceCheck(TArray<FName> TraceSockets)
{
	ARogueTowerEnemyCharacter* Enemy = Cast<ARogueTowerEnemyCharacter>(GetOwner());
	FVector TraceStart = Enemy->GetMesh()->GetSocketLocation(TraceSockets[0]);
	FVector TraceEnd = Enemy->GetMesh()->GetSocketLocation(TraceSockets[1]);

	FHitResult BoxTraceHit;

	UKismetSystemLibrary::BoxTraceSingleForObjects
	(
		this,
		TraceStart,
		TraceEnd,
		TraceBoxSize / 2.f,
		Enemy->GetActorRotation(),
		BoxtraceChannel,
		false,
		TArray<AActor*>(),
		ShowDegubShape ? EDrawDebugTrace::Persistent : EDrawDebugTrace::None,
		BoxTraceHit,
		true
	);

	if (BoxTraceHit.GetActor())
	{
		OnHitTargetActor(BoxTraceHit.GetActor());
	}
}
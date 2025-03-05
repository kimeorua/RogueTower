// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combet/EnemyCombetComponent.h"
#include "Item/Weapon/RogueTowerEnemyWeapon.h"
#include "Components/BoxComponent.h"

void UEnemyCombetComponent::RegisterEnemyWeapon(ARogueTowerEnemyWeapon* InEnemyWeapon)
{
	if (!IsValid(InEnemyWeapon)) { return; }
	EnemyWeapon = InEnemyWeapon;
	EnemyWeapon->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
}

void UEnemyCombetComponent::CollisionOnOff(const ERogueTowerCombetCollisionType Type, bool Activate)
{
	if (!IsValid(EnemyWeapon)) { return; }
	
	if (Activate)
	{
		switch (Type)
		{
		case ERogueTowerCombetCollisionType::WeaponLeft:
			EnemyWeapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			break;

		case ERogueTowerCombetCollisionType::WeaponRight:
			break;

		default:
			break;
		}
	}
	else
	{
		EnemyWeapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OverlapedActors.Empty();
	}
}

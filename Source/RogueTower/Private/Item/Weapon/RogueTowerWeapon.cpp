// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/RogueTowerWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

ARogueTowerWeapon::ARogueTowerWeapon()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	WeaponCollision->SetupAttachment(GetRootComponent());
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

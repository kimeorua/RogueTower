// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/RogueTowerWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "RogueTowerFunctionLibrary.h"

ARogueTowerWeapon::ARogueTowerWeapon()
{
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	WeaponCollision->SetupAttachment(GetRootComponent());
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionBoxBegineOverlap);
}

void ARogueTowerWeapon::OnCollisionBoxBegineOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* WeaponOwningPawn = Cast<APawn>(GetOwner());

	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (URogueTowerFunctionLibrary::IsTargetPawnHostile(WeaponOwningPawn, HitPawn))
		{
			OnWeaponHitTarget.ExecuteIfBound(OtherActor);
		}
	}
}
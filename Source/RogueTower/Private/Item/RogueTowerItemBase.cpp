// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RogueTowerItemBase.h"

// Sets default values
ARogueTowerItemBase::ARogueTowerItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ARogueTowerItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

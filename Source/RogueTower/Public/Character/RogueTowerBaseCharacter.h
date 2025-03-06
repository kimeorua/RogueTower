// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/PawnCombetInterface.h"
#include "AbilitySystemInterface.h"
#include "Interface/PawnUIInterface.h"
#include "RogueTowerBaseCharacter.generated.h"

class URogueTowerAbilitySystemComponent;
class URogueTowerAttributeSet;
class UDataAsset_StartUpBase;
class UMotionWarpingComponent;

	UCLASS()
	class ROGUETOWER_API ARogueTowerBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombetInterface, public IPawnUIInterface
	{
		GENERATED_BODY()

	public:
		// Sets default values for this character's properties
		ARogueTowerBaseCharacter();

		// ~Begin IPawnCombetInterface
		virtual UPawnCombetComponent* GetPawnCombetComponent() const override;
		// ~End IPawnCombetInterface

		// ~Begin IAbilitySystemInterface
		virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
		// ~End IAbilitySystemInterface

		// ~Begin IPawnUIInterface
		virtual UPawnUIComponent* GetPawnUIComponent() const override;
		// ~End IPawnUIInterface

	protected:
		//~ Begin APawn Interface.
		virtual void PossessedBy(AController* NewController) override;
		//~ End APawn Interface

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
		URogueTowerAbilitySystemComponent* RogueTowerAbilitySystemComponent;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
		URogueTowerAttributeSet* RogueTowerAttributeSet;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data")
		TSoftObjectPtr<UDataAsset_StartUpBase> StartUpData;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MotionWarping")
		UMotionWarpingComponent* MotionWarpingComponent;

	public:
		FORCEINLINE URogueTowerAbilitySystemComponent* GetRogueTowerAbilitySystemComponent() const { return RogueTowerAbilitySystemComponent; }
		FORCEINLINE URogueTowerAttributeSet* GetogueTowerAttributeSet() const { return RogueTowerAttributeSet; }
	};

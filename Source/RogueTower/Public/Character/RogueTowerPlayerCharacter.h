// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RogueTowerBaseCharacter.h"
#include "GameplayTagContainer.h"
#include "RogueTowerPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
class UPlayerCombetComponent;

struct FInputActionValue;
/**
 * 
 */
UCLASS()
class ROGUETOWER_API ARogueTowerPlayerCharacter : public ARogueTowerBaseCharacter
{
	GENERATED_BODY()

public:
	ARogueTowerPlayerCharacter();

	// ~Begin IPawnCombetInterface
	virtual UPawnCombetComponent* GetPawnCombetComponent() const override;
	virtual UPlayerCombetComponent* GetPlayerCombetComponent() const override;
	// ~End IPawnCombetInterface

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FllowCamera;
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move_Forward();
	void Input_Move_Back();
	void Input_Move_Left();
	void Input_Move_Right();

	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

#pragma endregion

#pragma region Combets
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combet", meta = (AllowPrivateAccess = "true"))
	UPlayerCombetComponent* PlayerCombetComponent;
};

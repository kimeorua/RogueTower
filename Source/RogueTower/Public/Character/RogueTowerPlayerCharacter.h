// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RogueTowerBaseCharacter.h"
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

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

	virtual UPawnCombetComponent* GetPawnCombetComponent() const override;
	virtual UPlayerCombetComponent* GetPlayerCombetComponent() const override;

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

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion

#pragma region Combets
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combet", meta = (AllowPrivateAccess = "true"))
	UPlayerCombetComponent* PlayerCombetComponent;
};

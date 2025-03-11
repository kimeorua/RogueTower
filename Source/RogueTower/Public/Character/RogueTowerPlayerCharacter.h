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
class UInputMappingContext;
class UPlayerUIComponent;

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

	// ~Begin IPawnUIInterface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UPlayerUIComponent* GetPlayerUIComponent() const override;
	// ~End IPawnUIInterface

	void AddInputContext(UInputMappingContext* WeaponInputContext);

	UFUNCTION(BlueprintImplementableEvent)
	void SettingLockOnSpringArmLocation(bool bIsLockOn = true);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

private:
	bool IsMoveForward = false;
	bool IsMoveBack = false;
	bool IsMoveRight = false;
	bool IsMoveLeft = false;

#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FllowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combet", meta = (AllowPrivateAccess = "true"))
	UPlayerCombetComponent* PlayerCombetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UPlayerUIComponent* PlayerUIComponent;

#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move_Forward(const FInputActionValue& Value);
	void Input_Move_Right(const FInputActionValue& Value);
	void Input_Move_End();

	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

#pragma endregion

};

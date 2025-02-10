// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RogueTowerPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "Component/Input/RogueTowerInputComponent.h"
#include "RogueTowerTags.h"
#include "Engine/LocalPlayer.h"
#include "Component/Combet/PlayerCombetComponent.h"

ARogueTowerPlayerCharacter::ARogueTowerPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SocketOffset = FVector(0.f, 45.f, 75.f);
	SpringArm->bUsePawnControlRotation = true;

	FllowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FllowCamera"));
	FllowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FllowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	PlayerCombetComponent = CreateDefaultSubobject<UPlayerCombetComponent>(TEXT("PlayerCombetComponent"));
}

void ARogueTowerPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgat to assign a vaild data asset InputConfig"))

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(SubSystem);

	SubSystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	URogueTowerInputComponent* RogueTowerInputComponen = CastChecked<URogueTowerInputComponent>(PlayerInputComponent);

	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void ARogueTowerPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

UPawnCombetComponent* ARogueTowerPlayerCharacter::GetPawnCombetComponent() const
{
	return PlayerCombetComponent;
}

UPlayerCombetComponent* ARogueTowerPlayerCharacter::GetPlayerCombetComponent() const
{
	return PlayerCombetComponent;
}

void ARogueTowerPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (MovementVector.Y != 0.0f)
	{
		const FVector ForwardDirection = MovementRotator.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.0f)
	{
		const FVector RightDirection = MovementRotator.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ARogueTowerPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.0f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y != 0.0f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

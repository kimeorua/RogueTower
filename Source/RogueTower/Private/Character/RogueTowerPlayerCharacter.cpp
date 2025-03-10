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
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "DataAsset/StartUp/DataAsset_StartUpBase.h"
#include "Component/UI/PlayerUIComponent.h"

ARogueTowerPlayerCharacter::ARogueTowerPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 320.0f;
	SpringArm->SocketOffset = FVector(0.f, 45.f, 75.f);
	SpringArm->bUsePawnControlRotation = true;

	FllowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FllowCamera"));
	FllowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FllowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 250.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	PlayerCombetComponent = CreateDefaultSubobject<UPlayerCombetComponent>(TEXT("PlayerCombetComponent"));
	PlayerUIComponent = CreateDefaultSubobject<UPlayerUIComponent>(TEXT("PlayerUIComponent"));
}

void ARogueTowerPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgat to assign a vaild data asset InputConfig"))

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(SubSystem);

	SubSystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	URogueTowerInputComponent* RogueTowerInputComponen = CastChecked<URogueTowerInputComponent>(PlayerInputComponent);

	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Move_Forward, ETriggerEvent::Triggered, this, &ThisClass::Input_Move_Forward);
	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Move_Back, ETriggerEvent::Triggered, this, &ThisClass::Input_Move_Back);
	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Move_Left, ETriggerEvent::Triggered, this, &ThisClass::Input_Move_Left);
	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Move_Right, ETriggerEvent::Triggered, this, &ThisClass::Input_Move_Right);
	RogueTowerInputComponen->BindNativeInputAction(InputConfigDataAsset, RogueTowerTag::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	RogueTowerInputComponen->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void ARogueTowerPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueTowerPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!StartUpData.IsNull())
	{
		if (UDataAsset_StartUpBase* LoadData = StartUpData.LoadSynchronous())
		{
			LoadData->GiveToAbilitySystemComponent(RogueTowerAbilitySystemComponent);
		}
	}
}

UPawnCombetComponent* ARogueTowerPlayerCharacter::GetPawnCombetComponent() const
{
	return PlayerCombetComponent;
}

UPlayerCombetComponent* ARogueTowerPlayerCharacter::GetPlayerCombetComponent() const
{
	return PlayerCombetComponent;
}

UPawnUIComponent* ARogueTowerPlayerCharacter::GetPawnUIComponent() const
{
	return PlayerUIComponent;
}

UPlayerUIComponent* ARogueTowerPlayerCharacter::GetPlayerUIComponent() const
{
	return PlayerUIComponent;
}

void ARogueTowerPlayerCharacter::AddInputContext(UInputMappingContext* WeaponInputContext)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(SubSystem);

	SubSystem->AddMappingContext(WeaponInputContext, 1);
}

void ARogueTowerPlayerCharacter::Input_Move_Forward()
{
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	const FVector ForwardDirection = MovementRotator.RotateVector(FVector::ForwardVector);
	AddMovementInput(ForwardDirection, 1.0f);
}

void ARogueTowerPlayerCharacter::Input_Move_Back()
{
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	const FVector ForwardDirection = MovementRotator.RotateVector(FVector::ForwardVector);
	AddMovementInput(ForwardDirection, -1.0f);
}

void ARogueTowerPlayerCharacter::Input_Move_Left()
{
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	const FVector ForwardDirection = MovementRotator.RotateVector(FVector::RightVector);
	AddMovementInput(ForwardDirection, -1.0f);
}

void ARogueTowerPlayerCharacter::Input_Move_Right()
{
	const FRotator MovementRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	const FVector ForwardDirection = MovementRotator.RotateVector(FVector::RightVector);
	AddMovementInput(ForwardDirection, 1.0f);
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

void ARogueTowerPlayerCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	RogueTowerAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ARogueTowerPlayerCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	RogueTowerAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}

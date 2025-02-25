// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GAS/RogueTowerAbilitySystemComponent.h"
#include "RogueTowerAttributeSet.generated.h"


class IPawnUIInterface;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 * 
 */
UCLASS()
class ROGUETOWER_API URogueTowerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	URogueTowerAttributeSet();
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;
	
	UPROPERTY(BlueprintReadOnly, Category = "HP")
	FGameplayAttributeData CurrentHP;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, CurrentHP)

	UPROPERTY(BlueprintReadOnly, Category = "HP")
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, MaxHP)

	UPROPERTY(BlueprintReadOnly, Category = "SP")
	FGameplayAttributeData CurrentSP;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, CurrentSP)

	UPROPERTY(BlueprintReadOnly, Category = "SP")
	FGameplayAttributeData MaxSP;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, MaxSP)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData ATK;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, ATK)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DEF;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, DEF)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData ATTSPD;
	ATTRIBUTE_ACCESSORS(URogueTowerAttributeSet, ATTSPD)

private:
	TWeakInterfacePtr<IPawnUIInterface> ChacedPawnUIInterface;
};

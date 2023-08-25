// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

class UAuraAttributeSet;



#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY();

	FEffectProperties() {}

	FGameplayEffectContextHandle EffectContexthandle;

	//Source
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;
	//End Source
	// 
	//Target
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
	//End Target

};

UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; 


	/*Changes to currentvalue before the changes happens.Clamps attribute from going below 0 or above maxhealth maxmana etc.
	// not most attractive choice for clamping. HP goes above max due to more then 1 modifier
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override; 
	*/


	/*Better then pre attribute
	//source = causer of the effect, Target = target of the effect (Owner of this attributeSet)
	//Set the clamp here so hp pickups dont go above max regardless of how many query modifiers. 
	*/
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override; 


	//Attributes have this FGameplayAttributeData.
	//ReplicatedUsing = the function OnRep_health
	//1. Steps, You Declare Variable, You Replicate it in UPROPERTY
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health; 
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData Maxhealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Maxhealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana; 
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	//2. Create RepNotify to accept old value
	//HEALTH
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	//ENDHEALTH

	//MANA
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	//END MANA



private:
	//This function is to avoid cluttering the PostGameplayEffectExecute function. We add struct for variables.
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const; 

	void SetClampProperties(const FGameplayEffectModCallbackData& Data);

};

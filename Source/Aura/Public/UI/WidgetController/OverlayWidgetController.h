// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
 

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:

	virtual void BroadcastInitialValues() override;

	virtual void BindCallbacksToDependencies() override;


	//Delegate variables for Blueprints start
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnMaxHealthChangedSignature OnMaxHealthChanged;
	//Delegate end

protected:

	 void HealthChanged(const FOnAttributeChangeData& Data) const;
	 void MaxHealthChanged(const FOnAttributeChangeData& Data) const; 

};
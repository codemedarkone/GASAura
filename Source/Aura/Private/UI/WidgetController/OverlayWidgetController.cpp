// CopyRight Red Project


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"



void UOverlayWidgetController::BroadcastInitialValues()
{
	/*All we are doing is assigning the variable AuraAttributeSet = AttributeSet so that we can use AuraAttributeSet variables 
	from UAuraAttributeSet in this class. This class has a type UAttributeSet variable which we assign to AuraAttributeSet. 
	Then we use AuraAttributeSet to get the variables it has since the parent class is UAttributeSet* Attribute can cast to its child
	which is the UAuraAttributeSet. 	
	*/
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

		//Using our delegate OnHealthChanged/OnMaxHealthChanged we broadcast the auraAttributes->gethealth which we have access to
		OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxhealth());
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
			AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
			AuraAttributeSet->GetMaxhealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue); 
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}


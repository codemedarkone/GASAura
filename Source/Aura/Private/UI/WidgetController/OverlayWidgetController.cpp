// CopyRight Red Project


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

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



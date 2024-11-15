// CopyRight Red Project


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

//This class handles widgets overlay

void UOverlayWidgetController::BroadcastInitialValues()
{
	/*All we are doing is assigning the variable AuraAttributeSet = AttributeSet so that we can use AuraAttributeSet variables 
	from UAuraAttributeSet in this class. This class has a type UAttributeSet variable which we assign to AuraAttributeSet. 
	Then we use AuraAttributeSet to get the variables it has since the parent class is UAttributeSet* Attribute, which can cast to its child
	which is the UAuraAttributeSet. 	
	*/
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

		//Using our delegate OnHealthChanged/OnMaxHealthChanged we broadcast the auraAttributes->gethealth which we have access to
		OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxhealth());

		OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
		OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana()); 
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);

		/*Respond to when attributes change, health, mana etc.ASC has a function for this.
		This takes an FGameplayAttribute such as below. To bind to it you would use (.)AddUObject().
		To bind a callback to AddUobject(this, CallBackFunction) as shown below.

		GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute())
		
		*/

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
	);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxhealthAttribute()).AddLambda(
				[this](const FOnAttributeChangeData& Data)
				{
					OnMaxHealthChanged.Broadcast(Data.NewValue);
				}
		);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddLambda(
				[this](const FOnAttributeChangeData& Data)
				{
					OnManaChanged.Broadcast(Data.NewValue);
				}
		);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddLambda(
				[this](const FOnAttributeChangeData& Data)
				{
					OnMaxManaChanged.Broadcast(Data.NewValue);
				}
		);

		UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent);
		
		AuraASC->EffectAssetTags.AddLambda(
			[this](const FGameplayTagContainer& AssetTags)
			{
				for (const FGameplayTag& Tag : AssetTags)
				{
					//for example, say that tag is message.healthpotion	
					// "Message.HealthPotion".MatchesTag("Message") will return true. "Message".MatchesTag("Message.HealthPotion") will return false
					FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
					if (Tag.MatchesTag(MessageTag))
					{
						const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
						MessageWidgetRowDelegate.Broadcast(*Row);
// 						const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
// 						GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg); 
					}
				}
			}
		); 		
}






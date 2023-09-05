// CopyRight Red Project


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound /*= false*/) const
{
	for (const FAuraInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction; 
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find ability input action for inputtag [%s], on Inputconfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	
	return nullptr; 
}

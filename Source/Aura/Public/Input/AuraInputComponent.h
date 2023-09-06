// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "AuraInputConfig.h"
#include "AuraInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:

	template<class UserClass, typename PressedFunctType, typename ReleasedFunctType, typename HeldFunctType>
	void BindAbilityActions(const UAuraInputConfig* inputConfig, UserClass* Object, PressedFunctType PressedFunct, ReleasedFunctType ReleasedFunct, HeldFunctType HeldFunct);


};

template<class UserClass, typename PressedFunctType, typename ReleasedFunctType, typename HeldFunctType>
void UAuraInputComponent::BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object, PressedFunctType PressedFunct, ReleasedFunctType ReleasedFunct, HeldFunctType HeldFunct)
{
	check(InputConfig)

	for (const FAuraInputAction& Action : InputConfig->AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag.IsValid())
		{

			if (PressedFunct)
			{
				BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunct, Action.InputTag);
			}

			if (ReleasedFunct)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunct, Action.InputTag);
			}

			if (HeldFunct)
			{
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunct, Action.InputTag);
			}
		}
	}
}

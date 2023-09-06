// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AuraGameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Input")
	FGameplayTag StartupInputTag; 
};

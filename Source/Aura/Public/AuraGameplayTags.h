// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 * 
 * Singleton Containing native Gameplay Tag
 */
struct FAuraGameplayTags 
{

public:
	static const FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGamplayTags(); 

	FGameplayTag Attributes_Secondary_Armor; 

protected:



private:

	static FAuraGameplayTags GameplayTags;


};
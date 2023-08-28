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

protected:



private:

	static FAuraGameplayTags GameplayTags;


};
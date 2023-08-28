// CopyRight Red Project


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"


FAuraGameplayTags FAuraGameplayTags::GameplayTags;



void FAuraGameplayTags::InitializeNativeGamplayTags()
{
	GameplayTags.Attributes_Secondary_Armor= UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves block chance")); 


}


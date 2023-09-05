// CopyRight Red Project


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"


FAuraGameplayTags FAuraGameplayTags::GameplayTags;



void FAuraGameplayTags::InitializeNativeGamplayTags()
{

	/*
	* Primary Attributes
	*/

	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Increases physical damage"));
	GameplayTags.Attributes_Primary_intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Increases magical damage"));
	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("Increases Armor and Armor Penetration"));
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Increases Health"));

	/*
	* Secondary Attributes
	*/
	GameplayTags.Attributes_Secondary_Armor= UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves block chance")); 
	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Increases critical and damage"));
	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), FString("Reduces damage taken, improves block"));
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("increases critical chance"));
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("increase critical damage"));
	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"), FString("Reduces critical damage chance"));
	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"), FString("Health regenerated"));
	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"), FString("Mana regenerated"));

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Maximum HP"));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Maximum MP"));


	/*
	* Input Tags
	*/
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"), FString("Input Tag for left mouse button"));
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"), FString("Input Tag for right mouse button"));
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"), FString("Input tag for 1 key"));
	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"), FString("Input tag for 2 key"));
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"), FString("Input tag for 3 key"));
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"), FString("Input tag for 4 key"));



}


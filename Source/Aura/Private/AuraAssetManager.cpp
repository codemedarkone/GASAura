// CopyRight Red Project


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"



UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine)

	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGamplayTags(); 

	//This is required to use TargetData
	UAbilitySystemGlobals::Get().InitGlobalData();
}

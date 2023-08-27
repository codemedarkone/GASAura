// CopyRight Red Project


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"


UMMC_MaxHealth::UMMC_MaxHealth()
{
	//Configured capture definition
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute(); 

	//Define whether we are capturing vigor from target or source
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	//capture attribute as soon as effect spec is created
	//not snapshot = getting true value at time of application of effect
	VigorDef.bSnapshot = false; 

	//MMC needs variables of array to capture. 
	RelevantAttributesToCapture.Add(VigorDef); 

}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather Tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags(); 

	//In order to capture an attribute and get its value
	FAggregatorEvaluateParameters EvaluationParameters; 
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	//In order to capture the attribute we are interested in. In this case Vigor
	float Vigor = 0.f; 
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvaluationParameters, Vigor);

	//clamp it and make sure its never a negative value
	Vigor = FMath::Max<float>(Vigor, 0.f); 

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 80.f + 2.5f * Vigor + 10.f * PlayerLevel; 

}

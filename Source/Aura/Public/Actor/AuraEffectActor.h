// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"


class USphereComponent; 
class UGameplayEffect;
UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();



protected:
	virtual void BeginPlay() override;

public:


protected:

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor * TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass); 


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass; 

private:

	

};

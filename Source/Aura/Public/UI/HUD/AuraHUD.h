// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	

protected:

	virtual void BeginPlay();

private:

	UPROPERTY(EditAnywhere); 
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass; 
};

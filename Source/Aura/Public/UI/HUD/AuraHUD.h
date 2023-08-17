// CopyRight Red Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;
class UAbilitySystemComponent;
class UAttributeSet;
class APlayerController;
class APlayerState;

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
	
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams); 


	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS); 

protected:



private:

	UPROPERTY(EditAnywhere); 
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass; 

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	TObjectPtr<UOverlayWidgetController> OverlayWidgetController; 



};

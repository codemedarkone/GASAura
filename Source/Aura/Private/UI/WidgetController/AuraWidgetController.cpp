// CopyRight Red Project


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCparams)
{
	PlayerController = WCparams.PlayerController;
	PlayerState = WCparams.PlayerState;
	AbilitySystemComponent = WCparams.AbilitySystemComponent;
	AttributeSet = WCparams.AttributeSet; 
}

void UAuraWidgetController::BroadcastInitialValues()
{

}

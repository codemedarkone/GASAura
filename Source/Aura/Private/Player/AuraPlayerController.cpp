// CopyRight Red Project


#include "Player/AuraPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"



AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; 


}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay(); 

	check(AuraContext); 

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem); 
	Subsystem->AddMappingContext(AuraContext, 0); 

	bShowMouseCursor = true; 
	DefaultMouseCursor = EMouseCursor::Default;

	//we can use input from keyboard and mouse and to use inputs to affect ui such as widgets
	FInputModeGameAndUI InputModeData;
	//mouse wont be locked to viewport
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	//Once cursor is captured in viewport it wont hide it
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData); 


}

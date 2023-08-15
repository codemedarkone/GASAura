// CopyRight Red Project


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"






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

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); 

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move); 

}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>(); 
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f); 

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X); 
	}


}

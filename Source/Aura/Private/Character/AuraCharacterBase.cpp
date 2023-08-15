// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// void AAuraCharacterBase::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
// 
// }
// 
// void AAuraCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
// 
// }


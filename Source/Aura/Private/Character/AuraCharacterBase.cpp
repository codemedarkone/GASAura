// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Aura/Aura.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false); 
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore); 
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap); 
	GetMesh()->SetGenerateOverlapEvents(true); 

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon"); 
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket")); 
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent; 
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector AAuraCharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
	return Weapon->GetSocketLocation(WeaponTipSocketName); 
}

void AAuraCharacterBase::InitAbilityActorInfo()
{

}

void AAuraCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this); 
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f); 
}

void AAuraCharacterBase::AddCharacterAbilities()
{
	UAuraAbilitySystemComponent* AuraASC = CastChecked<UAuraAbilitySystemComponent>(AbilitySystemComponent); 

	if (!HasAuthority()) return;

	AuraASC->AddCharacterAbilities(StartupAbilities); 

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


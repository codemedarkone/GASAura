// CopyRight Red Project


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Net/UnrealNetwork.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	//Enable or Disable replication, online play
	AbilitySystemComponent->SetIsReplicated(true);
	/*
	Full - Single Player: Gameplay affects replicated to all clients
	Mixed - MultiPlayer, Player-Controlled: GamePlay Effects are Replicated to the owning client only
		Gameplay Cues and Gameplay Tags replicated to all clients
	Minimal - MultiPlayer, AI-Controlled: GamePlay effects are not replicated. Gameplay Cues and Gameplay Tags replicated to
		all clients. 
	I can make the game single player if I start with Mixed but I cannot make a multiPlayer after starting with Full. 
	*/
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); 

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	//prevent lag time the higher it is SetNetUpdateFrequency() or GetNetUpdateFrequency()
	/*
	// Was used before 5.5 update no its 
	// NetUpdateFrequency = 100.f; 
	*/
	SetNetUpdateFrequency(100); 
}






void AAuraPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps); 

	DOREPLIFETIME(AAuraPlayerState, Level); 
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent; 
}

void AAuraPlayerState::OnRep_Level(int32 OldLevel)
{

}

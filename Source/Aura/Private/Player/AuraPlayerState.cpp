// CopyRight Red Project


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

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

	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");

	//prevent lag time the higher it is
	NetUpdateFrequency = 100.f; 
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent; 
}

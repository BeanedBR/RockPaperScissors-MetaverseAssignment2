// Fill out your copyright notice in the Description page of Project Settings.


#include "RockPaperScissorsGameState.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerState.h"

void ARockPaperScissorsGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARockPaperScissorsGameState, PlayerChoices);
}

void ARockPaperScissorsGameState::OnRep_PlayerChoices()
{
	UE_LOG(LogTemp, Log, TEXT("PlayerChoices replicated. Array size: %d"), PlayerChoices.Num());
}

void ARockPaperScissorsGameState::UpdatePlayerChoice(APlayerState* PlayerState, const FString& NewChoice1, const FString& NewChoice2)
{
	if (!PlayerState) return;

	if (HasAuthority())
	{
		for (FPlayerChoice& Entry : PlayerChoices)
		{
			if (Entry.PlayerName == PlayerState->GetPlayerName())
			{
				Entry.Choice1 = NewChoice1;
				Entry.Choice2 = NewChoice2;
				return;
			}
		}
	}

	FPlayerChoice NewEntry;
	NewEntry.PlayerName = PlayerState->GetPlayerName();
	NewEntry.Choice1 = NewChoice1;
	NewEntry.Choice2 = NewChoice2;

	PlayerChoices.Add(NewEntry);
}


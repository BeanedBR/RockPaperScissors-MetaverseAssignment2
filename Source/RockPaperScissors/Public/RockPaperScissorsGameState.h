// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RockPaperScissorsGameState.generated.h"

USTRUCT(BlueprintType)
struct FPlayerChoice
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FString PlayerName;

	UPROPERTY(BlueprintReadOnly)
	FString Choice1;

	UPROPERTY(BlueprintReadOnly)
	FString Choice2;
};

UCLASS()
class ROCKPAPERSCISSORS_API ARockPaperScissorsGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(ReplicatedUsing=OnRep_PlayerChoices, BlueprintReadOnly)
	TArray<FPlayerChoice> PlayerChoices;

	UFUNCTION()
	void OnRep_PlayerChoices();

	void UpdatePlayerChoice(APlayerState* PlayerState, const FString& NewChoice1, const FString& NewChoice2);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};

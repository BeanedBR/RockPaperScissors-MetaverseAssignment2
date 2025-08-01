// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RockPaperScissorsGameMode.generated.h"

UCLASS(minimalapi)
class ARockPaperScissorsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARockPaperScissorsGameMode();

	UFUNCTION(BlueprintCallable)
	void HostLANGame();

	UFUNCTION(BlueprintCallable)
	void JoinLANGame();

	UFUNCTION(BlueprintCallable)
	void PrintAllPlayerChoices();
};




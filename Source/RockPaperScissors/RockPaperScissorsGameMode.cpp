// Copyright Epic Games, Inc. All Rights Reserved.

#include "RockPaperScissorsGameMode.h"
#include "RockPaperScissorsCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "RockPaperScissors/Public/RockPaperScissorsGameState.h"

ARockPaperScissorsGameMode::ARockPaperScissorsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
        GameStateClass = ARockPaperScissorsGameState::StaticClass();
	}
}

void ARockPaperScissorsGameMode::HostLANGame()
{
    GetWorld()->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void ARockPaperScissorsGameMode::JoinLANGame()
{
    APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController();
    if (PC)
    {
        PC->ClientTravel("192.168.0.57", TRAVEL_Absolute); // Hard coded with a IPV4 address. Change this to your own if you want to test LAN connection.
    }
}

void ARockPaperScissorsGameMode::PrintAllPlayerChoices()
{
    UWorld* World = GetWorld();
    if (!World) return;

    for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
    {
        APlayerController* PC = It->Get();
        if (PC && PC->GetPawn())
        {
            ARockPaperScissorsCharacter* Ch = Cast<ARockPaperScissorsCharacter>(PC->GetPawn());
            if (Ch)
            {
                FString Message = Ch->Choice1;
                GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, Message);
            }
        }
    }
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopdownBaseGameMode.h"
#include "TopdownBasePlayerController.h"
#include "TopdownBaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopdownBaseGameMode::ATopdownBaseGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopdownBasePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
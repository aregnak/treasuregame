// Copyright Epic Games, Inc. All Rights Reserved.

#include "TreasureGameGameMode.h"
#include "TreasureGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATreasureGameGameMode::ATreasureGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

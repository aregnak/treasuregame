// Copyright Epic Games, Inc. All Rights Reserved.

#include "cpptestGameMode.h"
#include "cpptestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AcpptestGameMode::AcpptestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

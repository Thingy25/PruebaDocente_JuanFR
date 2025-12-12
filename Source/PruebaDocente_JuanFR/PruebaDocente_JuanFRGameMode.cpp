// Copyright Epic Games, Inc. All Rights Reserved.

#include "PruebaDocente_JuanFRGameMode.h"
#include "PruebaDocente_JuanFRCharacter.h"
#include "UObject/ConstructorHelpers.h"

APruebaDocente_JuanFRGameMode::APruebaDocente_JuanFRGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "GroupProjectTestBlue.h"
#include "GroupProjectTestBlueGameMode.h"
#include "GroupProjectTestBlueCharacter.h"

AGroupProjectTestBlueGameMode::AGroupProjectTestBlueGameMode()
{
	// Set up the defaults for this gamemode:
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ProjectWinterCPP/Blueprints/ProjectWinterCharacter"));
	
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

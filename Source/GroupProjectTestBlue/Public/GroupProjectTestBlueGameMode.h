// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "Pickup.h"
#include "GroupProjectTestBlueGameMode.generated.h"

UCLASS(minimalapi)
class AGroupProjectTestBlueGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AGroupProjectTestBlueGameMode();

protected:

	/** The pick-ups that are currently present in the level */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ActorCollections)
	TArray<APickup*> CurrentPickupsInLevel;

};




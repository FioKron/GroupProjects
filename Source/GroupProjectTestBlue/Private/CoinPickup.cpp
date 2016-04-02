// Fill out your copyright notice in the Description page of Project Settings.

#include "GroupProjectTestBlue.h"
#include "CoinPickup.h"


// Sets default values
ACoinPickup::ACoinPickup()
{
 	// Left as is for now:
	PrimaryActorTick.bCanEverTick = true;
	
	// Initilise the member variables of this coin:

	CoinValue = 1; // (1 for testing purposes)

	PickupType = EPickupType::PT_COIN;
}


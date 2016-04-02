// Fill out your copyright notice in the Description page of Project Settings.

#include "GroupProjectTestBlue.h"
#include "Pickup.h"


// Set up this object:
APickup::APickup()
{
	// Allow this actor to tick for now:
	PrimaryActorTick.bCanEverTick = true;

	// The Player will not be near to this pickup when play begins:
	bIsPlayerNearPickup = false;

	// Initilise the ProximityDetectionSphere:
	ProximityDetectionSphere = CreateDefaultSubobject<USphereComponent>("ProximityDetectionSphere");
	ProximityDetectionSphere->SetSphereRadius(32.0f);

	// Default to the first value (on initilisation):
	PickupType = EPickupType::PT_HEALTH;
}

// Set the flag's value as appropriate:
void APickup::PlayerIsNearToThisPickup()
{
	bIsPlayerNearPickup = true;
}

void APickup::PlayerIsNotNearThisPickup()
{
	bIsPlayerNearPickup = false;
}

// Get the ID for this Pickup: 
int32 APickup::GetPickupID()
{
	return PickupID;
}

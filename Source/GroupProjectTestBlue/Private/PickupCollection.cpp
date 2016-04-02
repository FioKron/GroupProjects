// Fill out your copyright notice in the Description page of Project Settings.

#include "GroupProjectTestBlue.h"
#include "PickupCollection.h"


// The primary constructor for this class:
APickupCollection::APickupCollection()
{
 	// Allow ticking for now:
	PrimaryActorTick.bCanEverTick = true;
}

// To add Pickups:
void APickupCollection::AddPickupToCollection(APickup* PickupToAdd)
{
	if (PickupToAdd != NULL)
	{
		PrimaryCollectionComponent.Add(PickupToAdd);
	}
}

// For removing a Pickup identified by PickupToRemove:
APickup* APickupCollection::RemovePickupFromCollection(int32 PickupToRemove)
{
	// The return value
	APickup* PickupRemoved = CreateAbstractDefaultSubobject<APickup>(TEXT("PickupRemoved"));

	// Other local variables
	int32 CurrentPickupIndex = 0;
	bool FirstItemRemoved = false;

	// Check each value in the array:
	do
	{
		if (PrimaryCollectionComponent[CurrentPickupIndex]->GetPickupID() == PickupToRemove)
		{
			PickupRemoved = PrimaryCollectionComponent[CurrentPickupIndex];

			PrimaryCollectionComponent.RemoveAt(CurrentPickupIndex);

			// Break out of this loop:
			FirstItemRemoved = true;
		}

		CurrentPickupIndex++;

	} while (CurrentPickupIndex < PrimaryCollectionComponent.Num() || FirstItemRemoved);

	return PickupRemoved;
}

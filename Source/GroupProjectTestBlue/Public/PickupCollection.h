// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.h"
#include "PickupCollection.generated.h"

UCLASS()
class GROUPPROJECTTESTBLUE_API APickupCollection : public AActor
{
	GENERATED_BODY()
	
public:	

	// Functions:

	/** The primary constructor */
	APickupCollection();

	/** 
		Functions for manipulating this collection

		@Param: 

		APickup* PickupToAdd: The Pickup to add to the collection.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add a Pickup"), Category = PrimaryComponentManipulation)
	void AddPickupToCollection(APickup* PickupToAdd);

	/** 
		Note that the value removed from this collection will be returned 
		
		@Param:

		int32 PickupToRemove: The unique ID of the Pickup to remove from the collection.

		@Return:

		APickup* PickupRemoved: The pickup that has been removed.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove a Pickup"), Category = PrimaryComponentManipulation)
	APickup* RemovePickupFromCollection(int32 PickupToRemove);

protected:

	/** To store all of the Pickups within a level */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PrimaryComponent)
	TArray<APickup*> PrimaryCollectionComponent;
	
};

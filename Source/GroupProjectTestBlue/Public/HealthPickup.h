// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class GROUPPROJECTTESTBLUE_API AHealthPickup : public APickup
{
	GENERATED_BODY()
	
public:
	
	// Functions:

	/** For setting up this health pickup */
	AHealthPickup();

	// Variables:

	/** This health value that the Player will gain, when picking this up */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameplayMechanic)
	int32 HealthValue;
};

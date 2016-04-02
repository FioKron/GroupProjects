// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.h"
#include "CoinPickup.generated.h"

UCLASS()
class GROUPPROJECTTESTBLUE_API ACoinPickup : public APickup
{
	GENERATED_BODY()
	
public:	
	
	// Functions:

	/** For setting up this coin pickup */
	ACoinPickup();

	// Variables:

	/** This coin's value */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameplayMechanic)
	int32 CoinValue;
	
private: 

};

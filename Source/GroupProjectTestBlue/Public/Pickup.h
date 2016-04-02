// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class GROUPPROJECTTESTBLUE_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	

	// Enums:

	/** To be used in a member variable for the type of pickup that any particular instance is */
	UENUM(BlueprintType, Category = Enums)
	enum class EPickupType : uint8
	{
		PT_HEALTH	UMETA(DisplayName = "HealthPickup"),
		PT_COIN		UMETA(DisplayName = "CoinPickup")
	};

	// Functions: 

	/** Standard constructor for a Pickup */
	APickup();

	/** For checking when the Player is near this pickup, the function below is for when they are not */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "The Player Is Within This Pickup's Sphere of Influence."), Category = Proximity)
	void PlayerIsNearToThisPickup();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "The Player Is Not Within This Pickup's Sphere of Influence."), Category = Proximity)
	void PlayerIsNotNearThisPickup();

	/** Get this Pickup's ID */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get PickupID"), Category = Proximity)
	int32 GetPickupID();

protected:

	/** Variables: */

	/** The flag to be used to determine if the player is near the pickup */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Proximity)
	bool bIsPlayerNearPickup;

	/** This sphere is for the purpose of gauging if the Player is near to this pickup */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Proximity)
	USphereComponent* ProximityDetectionSphere;

	/** An identity for this Pickup */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Identification)
	EPickupType PickupType;

	/** This Pickup's ID */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Identification)
	int32 PickupID;
};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectWinterCharacter.h"
#include "PickupCollection.h"
#include "ProjectWinterPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GROUPPROJECTTESTBLUE_API AProjectWinterPlayerCharacter : public AProjectWinterCharacter
{
	GENERATED_BODY()
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:

	// Functions:

	/** Increment the Player's score by 1 (if the Player picks up a coin for example) */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Increment Current Score"), Category = GameMechanics)
	void IncrementCurrentScore();

	/** The standard constructor for this class */
	AProjectWinterPlayerCharacter();

	/** To be called to update references to any and all Pickups, within the current level */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Pickup References"), Category = PickupFunctions)
	void UpdatePickupReferences(APickupCollection* LatestVersion);

	// Variables:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:

	// Variables:

	/** The Player's score */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameMechanicComponents)
	int32 CurrentPlayerScore;

	/** A reference to the current level's collection of Pickups */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PickupComponents)
	APickupCollection* LevelPickupCollectionRef;

	// Functions:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
	
};

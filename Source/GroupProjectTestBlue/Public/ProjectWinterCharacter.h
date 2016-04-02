// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GroupProjectTestBlueCharacter.h"
#include "ProjectWinterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GROUPPROJECTTESTBLUE_API AProjectWinterCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:

	// Functions:

	/** 
		To modify this character's health 
		
		@Param. :

		int HealthModValue: The value to modify this character's health by, the absolute of this value will be obtained.

		bool bHealCharacter: This value is to check whether to heal or damage the character.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Damage or Heal This Character"), Category = GameMechanics)
	void ModifyHealth(int32 HealthModValue, bool bHealCharacter);

protected:

	/** Standard constructor for a Project Winter Character */
	AProjectWinterCharacter();

	// Variables:

	/** This character's current, maximum and minimum health values */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameMechanicComponents)
	int32 CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameMechanicComponents)
	int32 MinimumHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameMechanicComponents)
	int32 MaximumHealth;
};

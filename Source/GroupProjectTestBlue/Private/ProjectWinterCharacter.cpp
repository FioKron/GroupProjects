// Fill out your copyright notice in the Description page of Project Settings.

#include "GroupProjectTestBlue.h"
#include "ProjectWinterCharacter.h"

AProjectWinterCharacter::AProjectWinterCharacter()
{

}

// Handle health modification, as appropriate:
void AProjectWinterCharacter::ModifyHealth(int32 HealthModValue, bool bHealCharacter)
{
	// So that numerical operations are not affected by negative values given as input:
	HealthModValue = abs(HealthModValue);

	// Heal the character:
	if (bHealCharacter)
	{
		CurrentHealth += HealthModValue;

		// Validation:
		if (CurrentHealth >= MaximumHealth)
		{
			CurrentHealth = MaximumHealth;
		}
	}
	// Damage the character:
	else
	{
		CurrentHealth -= HealthModValue;

		// Validiation:
		if (CurrentHealth <= MinimumHealth)
		{
			CurrentHealth = MinimumHealth;
		}
	}
}
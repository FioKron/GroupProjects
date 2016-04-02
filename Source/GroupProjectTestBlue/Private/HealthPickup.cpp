// Fill out your copyright notice in the Description page of Project Settings.

#include "GroupProjectTestBlue.h"
#include "HealthPickup.h"

// Initilise values:
AHealthPickup::AHealthPickup()
{
	HealthValue = 15;
	PickupType = EPickupType::PT_HEALTH;
}



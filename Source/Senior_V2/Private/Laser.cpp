// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"

#include "GameFramework/ProjectileMovementComponent.h"

ALaser::ALaser()
{
	InitialLifeSpan = 1.f;
	ProjectileMovementComp->InitialSpeed = 4000.f;
	ProjectileMovementComp->MaxSpeed = 4000.f;	
}

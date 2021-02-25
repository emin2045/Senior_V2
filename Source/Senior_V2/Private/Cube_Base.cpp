// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube_Base.h"


// Sets default values
ACube_Base::ACube_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACube_Base::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACube_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

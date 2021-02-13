// Fill out your copyright notice in the Description page of Project Settings.


#include "Launcher.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ALauncher::ALauncher()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));	// box componentimiz
	OverlapComp->SetBoxExtent(FVector(32, 32, 32));
	RootComponent = OverlapComp;

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ALauncher::OverlapLauncher); // &&&

	Strength = 2000.0;
	Angle = 60.f; // 

}

void ALauncher::OverlapLauncher(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* MyCharacter = Cast<ACharacter>(OtherActor);

	if (MyCharacter) 
	{
		FRotator Direction = MyCharacter->GetActorRotation();
		Direction.Pitch += Angle; // Pitch = Pitch + Angle
		FVector LaunchVelocity = UKismetMathLibrary::GetForwardVector(Direction) * Strength;

		MyCharacter->LaunchCharacter(LaunchVelocity, true, true);	// ctrl + k + d
	}
}

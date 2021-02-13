// Fill out your copyright notice in the Description page of Project Settings.


#include "Launcher.h"

#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h"

// Sets default values
ALauncher::ALauncher()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = OverlapComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->SetupAttachment(RootComponent);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ALauncher::OverlapLaunchPad);

	LaunchStrength = 1500;
	LaunchPitchAngle = 35;
}

void ALauncher::OverlapLaunchPad(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchPitchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;

	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);
	if (OtherCharacter)
	{
		OtherCharacter->LaunchCharacter(LaunchVelocity, true, true);
		AudioComp->Play();
	}
}

void ALauncher::BeginPlay()
{
	Super::BeginPlay();

	FRotator NewRotation(0, -90, LaunchPitchAngle * -1);

	MeshComp->SetRelativeRotation(NewRotation, false, nullptr, ETeleportType::None);
}

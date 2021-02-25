// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"
#include "Net/UnrealNetwork.h"
#include "GeneratedCodeHelpers.h"

AMovingCube::AMovingCube()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	MeshComp->SetMobility(EComponentMobility::Movable);
	Health = 3.f;
	
	OnTakeAnyDamage.AddDynamic(this,&AMovingCube::OnDamageTaken);
}

void AMovingCube::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingCube::Tick(float DeltaTime)
{
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();

		if (JourneyTravelled >= JourneyLength)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Speed * DeltaTime * Direction;
		SetActorLocation(Location);
	}
}

void AMovingCube::OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("OnDamageTaken"));
	Health -= Damage;
	
	if(Health<=0)
	{
		Destroy();
	}
}

void AMovingCube::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMovingCube, Health);
}
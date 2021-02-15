// Fill out your copyright notice in the Description page of Project Settings.


#include "BounceBall.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABounceBall::ABounceBall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->SetSphereRadius(17.0);
	CollisionComp->SetMobility(EComponentMobility::Movable);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));

	ProjectileMovementComp->InitialSpeed = 2000.f;
	ProjectileMovementComp->MaxSpeed = 2000.f;
	ProjectileMovementComp->ProjectileGravityScale = 5.f;
	ProjectileMovementComp->bShouldBounce = true;
	ProjectileMovementComp->Bounciness = 1.f;

	bReplicates = true;
	SetReplicateMovement(true);

	BounceHealth = 4;
	CollisionComp->OnComponentHit.AddDynamic(this, &ABounceBall::ApplyDamageToCube);

}

void ABounceBall::ApplyDamageToCube(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{

	UE_LOG(LogTemp, Warning, TEXT("hello1"));

	if (OtherActor)
	{

		UGameplayStatics::ApplyDamage(OtherActor, 1.f, nullptr, nullptr, nullptr);
		UE_LOG(LogTemp, Warning, TEXT("hello2"));
	}

	BounceHealth--;
	
	if (BounceHealth <= 0)
	{
		Destroy();

	}
}
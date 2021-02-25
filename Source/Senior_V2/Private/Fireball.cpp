// Fill out your copyright notice in the Description page of Project Settings.


#include "Fireball.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFireball::AFireball()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->SetSphereRadius(15.0);
	CollisionComp->SetMobility(EComponentMobility::Movable);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	VFX_Fireball = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	VFX_Fireball->SetupAttachment(RootComponent);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));

	ProjectileMovementComp->InitialSpeed = 1800.f;
	ProjectileMovementComp->MaxSpeed = 1950.f;
	ProjectileMovementComp->ProjectileGravityScale = 0.f;
	ProjectileMovementComp->bShouldBounce = false;

	bReplicates = true;
	SetReplicateMovement(false);
	InitialLifeSpan = 14.2f;

	CollisionComp->OnComponentHit.AddDynamic(this, &AFireball::ApplyDamageToCube);
}

void AFireball::ApplyDamageToCube(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		UGameplayStatics::ApplyDamage(OtherActor, 1.f, nullptr, this, nullptr);
		Destroy();
	}
}

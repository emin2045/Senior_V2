// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitableBall.h"

#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASplitableBall::ASplitableBall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->SetSphereRadius(15.0);
	CollisionComp->SetMobility(EComponentMobility::Movable);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	TopSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TopSpawnPoint"));
	TopSpawnPoint->SetupAttachment(MeshComp);

	BottomSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("BottomSpawnPoint"));
	BottomSpawnPoint->SetupAttachment(MeshComp);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));

	ProjectileMovementComp->InitialSpeed = 1000.f;
	ProjectileMovementComp->MaxSpeed = 1000.f;
	ProjectileMovementComp->ProjectileGravityScale = 0.f;
	ProjectileMovementComp->bShouldBounce = false;

	bReplicates = true;
	SetReplicateMovement(false);
	InitialLifeSpan = 1.4f;

	CollisionComp->OnComponentHit.AddDynamic(this, &ASplitableBall::ApplyDamageToCube);

}

void ASplitableBall::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASplitableBall::SpawnTopBotFire, 1.f, false, 0.5f);

}

void ASplitableBall::ApplyDamageToCube(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		UGameplayStatics::ApplyDamage(OtherActor, 1.f, nullptr, this, nullptr);
		Destroy();
	}
}
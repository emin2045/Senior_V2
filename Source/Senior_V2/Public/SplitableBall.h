// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplitableBall.generated.h"

class UArrowComponent;
class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;


UCLASS()
class SENIOR_V2_API ASplitableBall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASplitableBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UArrowComponent* TopSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UArrowComponent* BottomSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* ProjectileMovementComp;

	UFUNCTION()
	void ApplyDamageToCube(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FTimerHandle SpawnTimerHandle;
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void SpawnTopBotFire();


};
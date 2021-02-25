// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cube_Base.h"
#include "MovingCube.generated.h"

class UStaticMeshComponent;

UCLASS()
class SENIOR_V2_API AMovingCube : public ACube_Base
{
	GENERATED_BODY()

public:
	AMovingCube();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "MovingCube")
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere,Category="Target")
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true),Category="Target")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Replicated)
	float Health;

	UFUNCTION()
	void OnDamageTaken(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
};

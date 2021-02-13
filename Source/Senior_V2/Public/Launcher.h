// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Launcher.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class UAudioComponent;

UCLASS()
class SENIOR_V2_API ALauncher : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALauncher();


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* AudioComp;

	UPROPERTY(EditInstanceOnly, Category = "Properties")
	float LaunchStrength;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float LaunchPitchAngle;

	UFUNCTION()
	void OverlapLaunchPad(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void BeginPlay() override;
	
};
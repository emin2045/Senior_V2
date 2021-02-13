// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Launcher.generated.h"

class UBoxComponent;

UCLASS()
class SENIOR_V2_API ALauncher : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALauncher();


protected:

	UPROPERTY(VisibleAnywhere, Category = "Properties")
	UBoxComponent* OverlapComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float Angle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float Strength;

	UFUNCTION()
	void OverlapLauncher(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
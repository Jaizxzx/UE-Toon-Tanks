// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Combat", meta = (AllowPrivate))
	float FireRange = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Combat", meta = (AllowPrivate))
	FTimerHandle FireRateTimerHandle;

	float FireRate = 0.5f;

	void CheckFireCondition();

	bool InFireRange();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetPlayerController() const { return TankPlayerController; }

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivate))
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivate))
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivate))
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivate))
	float TurnRate = 30.0f;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;

};

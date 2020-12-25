// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UCapsuleComponent *CapsuleComponent = nullptr;

	UPROPERTY()
	UStaticMeshComponent *BaseMesh = nullptr;

	UPROPERTY()
	UStaticMeshComponent *TurretMesh = nullptr;

	UPROPERTY()
	USceneComponent *ProjectileSpawnPoint = nullptr;
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

APawnTurret::APawnTurret() {}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimer, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction() 
{
    Super::HandleDestruction();
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
    // If player is alive
    if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
    {
        return;
    }

    // If player is in range of fire
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }
}

float APawnTurret::ReturnDistanceToPlayer()
{
    if (!PlayerPawn)
    {
        return 0.f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

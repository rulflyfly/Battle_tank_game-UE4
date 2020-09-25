// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    auto PlayerTank = GetPlayerTank();
    
    if (!ControlledTank)
    {
        //UE_LOG(LogTemp, Warning, TEXT("TankAIController doesn't posess a tank"));
    }
    else
    {
         //UE_LOG(LogTemp, Warning, TEXT("TankAIController posesses %s"), *ControlledTank->GetName());
    }
    
    if (!PlayerTank)
    {
        //UE_LOG(LogTemp, Warning, TEXT("TankAIController doesn't see a player tank"));
    }
    else
    {
         //UE_LOG(LogTemp, Warning, TEXT("TankAIController sees %s"), *PlayerTank->GetName());
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    
    if (GetPlayerTank())
    {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    }
}

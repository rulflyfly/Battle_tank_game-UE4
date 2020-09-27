// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Tank.h"



void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        //UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
    }
    else
    {
        //UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *ControlledTank->GetName());
    }
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

// "De-project" the screen position of the crosshair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector WorldLocation; // To be discarded
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const
{
    FHitResult Hit;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector LineTraceEnd = StartLocation + (LookDirection * LineTraceRange);
    
    if (GetWorld()->LineTraceSingleByChannel(
       Hit,
       StartLocation,
       LineTraceEnd,
       ECollisionChannel::ECC_Visibility))
    {
        HitLocation = Hit.Location;
        return true;
    }
    HitLocation = FVector(0);
    return false;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    // Find the crosshair position
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    FVector LookDirection;
    
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        // Line trace along that look direction, and see what we hit (up to max range)
        GetLookVectorHitLocation(HitLocation, LookDirection);
    }
    
    
    
    return true;
}

void ATankPlayerController::AimTowardsCrosshair() 
{
    if (!GetControlledTank()) { return; }
    
    FVector HitLocation; // out parameter
    if (GetSightRayHitLocation(HitLocation))
    {
        GetControlledTank()->AimAt(HitLocation);
    }
    // Get world location of linetrace through crosshair
        // if it hits the landscape
            // Tell controlled tank to aim at this point
    return;
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

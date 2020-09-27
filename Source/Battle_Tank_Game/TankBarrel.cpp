// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    auto Speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    auto  ElevationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
    auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
    
    SetRelativeRotation(FRotator(Elevation, 0, 0));
    return;
}

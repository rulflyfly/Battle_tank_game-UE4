// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    UE_LOG(LogTemp, Warning, TEXT("ROTATING"));
    auto Speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    auto  RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;
    
    SetRelativeRotation(FRotator(0, RawNewRotation, 0));
    return;
}

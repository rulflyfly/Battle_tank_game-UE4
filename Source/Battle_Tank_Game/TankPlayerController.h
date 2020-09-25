// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include


class ATank;
/**
 *
 */
UCLASS()
class BATTLE_TANK_GAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
    
    
public:
    ATank* GetControlledTank() const;
    void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    
    // Start the tank moving the barrel so that the shot
    // would hit where the crosshair intersects the world
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector& HitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    bool GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const;

private:
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = .5;
    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = .127;
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.;
};

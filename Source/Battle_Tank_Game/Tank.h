// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // has to be the lst included

UCLASS()
class BATTLE_TANK_GAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt(FVector HitLocation);
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
	// Sets default values for this pawn's properties
	ATank();
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};

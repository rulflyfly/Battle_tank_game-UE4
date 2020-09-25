// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // has to be the lst included

class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class BATTLE_TANK_GAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt(FVector HitLocation);
    
    UFUNCTION(BlueprintCallable, Category = SetUp)
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
	// Sets default values for this pawn's properties
	ATank();

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; // Starting value of 1000 m/s; 
    

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};

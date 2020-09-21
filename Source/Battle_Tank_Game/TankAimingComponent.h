// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_GAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
    
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    void AimAt(FVector HitLocation, float LaunchSpeed);
    
    // Sets default values for this component's properties
    UTankAimingComponent();
    
    void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	
private:
    UStaticMeshComponent* Barrel = nullptr;
   
};

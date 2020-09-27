// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
    if (!BarrelToSet) { return; }
    Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
    if (!TurretToSet) { return; }
    Turret = TurretToSet;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
    if (!Barrel) { return; }
    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
   // UE_LOG(LogTemp, Warning, TEXT("Barrel %s"), *StartLocation.ToString());
    
    
   if ( UGameplayStatics::SuggestProjectileVelocity(
                                this,
                                OutLaunchVelocity,
                                StartLocation,
                                HitLocation,
                                LaunchSpeed,
                                false,
                                0,
                                0,
                                ESuggestProjVelocityTraceOption::DoNotTrace)) // Paramemer must be present to avoid bug
   {
       auto Time = GetWorld()->GetTimeSeconds();
      // UE_LOG(LogTemp, Warning, TEXT("%f: Aim found"), Time);
       auto AimDirection = OutLaunchVelocity.GetSafeNormal();
       MoveBarrelTowards(AimDirection);
       MoveTurretTowards(AimDirection);
   }
    else
    {
        auto Time = GetWorld()->GetTimeSeconds();
       // UE_LOG(LogTemp, Warning, TEXT("%f: NO AIM"), Time);
    }
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
    // Workout the difference between current barrel rotation and AimDirection
    
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;
    
    // Move the barrel to the right amount this frame
    
    Barrel->Elevate(DeltaRotator.Pitch);
    
    // Given a max elevation speed and frame time
    return;
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
    auto TurretRotator = Turret->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - TurretRotator;
    
    Turret->Rotate(DeltaRotator.Yaw);
}

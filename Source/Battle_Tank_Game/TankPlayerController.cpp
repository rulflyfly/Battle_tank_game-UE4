// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
    return Casr<ATank>(GetPawn());
}

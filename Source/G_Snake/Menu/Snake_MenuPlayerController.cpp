// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/Menu/Snake_MenuPlayerController.h"

void ASnake_MenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());

	bShowMouseCursor = true;
}
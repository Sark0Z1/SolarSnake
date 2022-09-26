// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/Menu/Snake_MenuGameMode.h"
#include "Snake_MenuHUD.h"
#include "Snake_MenuPlayerController.h"

ASnake_MenuGameMode::ASnake_MenuGameMode()
{
	PlayerControllerClass=ASnake_MenuPlayerController::StaticClass();
	HUDClass=ASnake_MenuHUD::StaticClass();
}

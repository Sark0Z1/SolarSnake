// Fill out your copyright notice in the Description page of Project Settings.


#include "Snake_PlayerController.h"
#include "Snake_PauseWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"


void ASnake_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
	TotalScore();
}

void ASnake_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Pause", IE_Pressed, this, &ASnake_PlayerController::OnPauseGame);
}

void ASnake_PlayerController::OnPauseGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->SetPause(this);

	const auto PauseWidget = CreateWidget<UUserWidget>(GetWorld(), PauseWidgetClass);
	if (PauseWidget)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), OpenWidgetSound);
		PauseWidget->AddToViewport();
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}

void ASnake_PlayerController::TotalScore()
{
	if (!GetWorld()) return;
	
	const auto ScoreWidget = CreateWidget<UUserWidget>(GetWorld(), ScoreWidgetClass);
	if (ScoreWidget)
	{
		ScoreWidget->AddToViewport();
	}
}


void ASnake_PlayerController::IsDead()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->SetPause(this);

	const auto GameOverWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass);
	if (GameOverWidget)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), OpenWidgetSound);
		GameOverWidget->AddToViewport();
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}



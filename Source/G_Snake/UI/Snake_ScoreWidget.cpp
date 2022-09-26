// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/UI/Snake_ScoreWidget.h"
#include "G_Snake/G_SnakeGameModeBase.h"

int32 USnake_ScoreWidget::GetScore()
{
	const auto GameMode = Cast<AG_SnakeGameModeBase>(GetWorld()->GetAuthGameMode());
	if(!GameMode) return 0;
	CurrentScore = GameMode->GetScore();
	return CurrentScore;
}

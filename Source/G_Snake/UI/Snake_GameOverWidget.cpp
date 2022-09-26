// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/UI/Snake_GameOverWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USnake_GameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(ResetButton)
	{
		ResetButton->OnClicked.AddDynamic(this, &USnake_GameOverWidget::OnResetGame);
	}
}

void USnake_GameOverWidget::OnResetGame()
{
	UGameplayStatics::OpenLevel(this, LevelName);
}

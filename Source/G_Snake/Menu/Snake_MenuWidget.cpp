// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/Menu/Snake_MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Sound/SoundCue.h"

void USnake_MenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &USnake_MenuWidget::OnStartGame);
	}

	if (QuitGameButton)
	{
		QuitGameButton->OnClicked.AddDynamic(this, &USnake_MenuWidget::OnQuitGame);
	}
}

void USnake_MenuWidget::OnStartGame()
{
	UGameplayStatics::PlaySound2D(GetWorld(), StartGameSound);
	UGameplayStatics::OpenLevel(this, LevelName);
}

void USnake_MenuWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

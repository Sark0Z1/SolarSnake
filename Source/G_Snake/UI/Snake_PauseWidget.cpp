// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/UI/Snake_PauseWidget.h"
#include "Components/Button.h"
#include "GameFramework/GameModeBase.h"
#include "G_Snake/Snake_PlayerController.h"


void USnake_PauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(ClearPauseButton)
	{
		ClearPauseButton->OnClicked.AddDynamic(this, &USnake_PauseWidget::OnClearPause);
	}
}

void USnake_PauseWidget::OnClearPause()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->ClearPause();
	const auto Controller = Cast<ASnake_PlayerController>(GetOwningPlayer());
	if(!Controller)	return;
	Controller->SetInputMode(FInputModeGameOnly());
	Controller->bShowMouseCursor = false;
	SetVisibility(ESlateVisibility::Hidden);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/UI/Snake_ToMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USnake_ToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(ToMenuButton)
	{
		ToMenuButton->OnClicked.AddDynamic(this, &USnake_ToMenuWidget::OnMenu);
	}
}

void USnake_ToMenuWidget::OnMenu()
{
	UGameplayStatics::OpenLevel(this, MenuName);
}

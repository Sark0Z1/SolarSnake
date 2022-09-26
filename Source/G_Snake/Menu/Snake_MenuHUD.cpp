// Fill out your copyright notice in the Description page of Project Settings.


#include "G_Snake/Menu/Snake_MenuHUD.h"
#include "Snake_MenuWidget.h"
#include "Blueprint/UserWidget.h"

void ASnake_MenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MenuWidgetClass)
	{
		const auto MenuWidget = CreateWidget<USnake_MenuWidget>(GetWorld(), MenuWidgetClass);
		if (MenuWidget)
		{
			MenuWidget->AddToViewport();
		}
	}
}

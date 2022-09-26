// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Snake_GameOverWidget.generated.h"

class UButton;
UCLASS()
class G_SNAKE_API USnake_GameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UButton* ResetButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Game")
	FName LevelName = NAME_None;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnResetGame();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Snake_MenuWidget.generated.h"

class UButton;
class USoundCue;

UCLASS()
class G_SNAKE_API USnake_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UButton* StartGameButton;

	UPROPERTY(meta=(BindWidget))
	UButton* QuitGameButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="Sound")
	USoundCue* StartGameSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Game")
	FName LevelName = NAME_None;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnStartGame();

	UFUNCTION()
	void OnQuitGame();
};

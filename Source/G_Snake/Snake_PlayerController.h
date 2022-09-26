// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Snake_PlayerController.generated.h"

class USoundCue;

UCLASS()
class G_SNAKE_API ASnake_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void IsDead();
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="Sound")
	USoundCue* OpenWidgetSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> ScoreWidgetClass;

private:
	void OnPauseGame();

	void TotalScore();
};

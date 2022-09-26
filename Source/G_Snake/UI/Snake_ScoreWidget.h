// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Snake_ScoreWidget.generated.h"


UCLASS()
class G_SNAKE_API USnake_ScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UI")
	int32 GetScore(); 

protected:
	UPROPERTY()
	int32 CurrentScore;
	
};

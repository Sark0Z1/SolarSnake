// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Snake_ToMenuWidget.generated.h"

class UButton;
UCLASS()
class G_SNAKE_API USnake_ToMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UButton* ToMenuButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Game")
	FName MenuName = NAME_None;

	virtual void NativeOnInitialized() override;
	

private:
	UFUNCTION()
	void OnMenu();
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Snake_GameInstance.generated.h"

UCLASS()
class G_SNAKE_API USnake_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
		virtual void Init() override;
};

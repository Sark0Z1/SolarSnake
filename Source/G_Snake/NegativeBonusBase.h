// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BonusBase.h"
#include "NegativeBonusBase.generated.h"

/**
 * 
 */
UCLASS()
class G_SNAKE_API ANegativeBonusBase : public ABonusBase
{
	GENERATED_BODY()

public:
	virtual void Iteract(AActor* Interactor, bool bIsHead) override;
	
};

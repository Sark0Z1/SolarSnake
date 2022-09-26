// Fill out your copyright notice in the Description page of Project Settings.


#include "PositiveBonusBase.h"
#include "SnakeBase.h"

void APositiveBonusBase::Iteract(AActor* Interactor, bool bIsHead)
{
	Super::Iteract(Interactor, bIsHead);
	//We reload this function, couse we need set positive bonus to SnakeBase (MovementSpeed)
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->MovementSpeed -= 0.05;
			this->Destroy();
		}
	}
}

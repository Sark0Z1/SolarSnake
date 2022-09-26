// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodBase.h"
#include "SnakeBase.h"

AFoodBase::AFoodBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFoodBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFoodBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodBase::Iteract(AActor* Interactor, bool bIsHead)
{
	IInteractable::Iteract(Interactor, bIsHead);
	GameMode=Cast<AG_SnakeGameModeBase>(GetWorld()->GetAuthGameMode());
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->AddSnakeElements(1);
			this->Destroy();
			GameMode->SetScore(1);
			GameMode->CreateFoodActorAfterDestroy();
		}
	}
}


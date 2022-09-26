// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusBase.h"
#include "SnakeBase.h"

// Sets default values
ABonusBase::ABonusBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABonusBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABonusBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABonusBase::Iteract(AActor* Interactor, bool bIsHead)
{

	IInteractable::Iteract(Interactor, bIsHead);
	//If we catch bonus, he destroy
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			this->Destroy();
		}
	}
}


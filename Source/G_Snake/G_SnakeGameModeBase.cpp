// Copyright Epic Games, Inc. All Rights Reserved.


#include "G_SnakeGameModeBase.h"

#include "FoodBase.h"
#include <ctime>
#include "BonusBase.h"
#include "PlayerPawnBase.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogAG_SnakeGameModeBase, All, All);

void AG_SnakeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	CreateFoodActor();
	CreateTimer();
}

void AG_SnakeGameModeBase::CreateFoodActor()
{
	srand(time(NULL));
	float RandX = 1.01 * (rand() % 700 - 350);
	float RandY = 1.01 * (rand() % 1500 - 700);
	auto RandValue = FVector(RandX, RandY, 0.f);
	FActorSpawnParameters SpawnParameters;
	//But here we setting, Food will try to find a nearby non-colliding location, but will not spawn unless one is found
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	FoodActor = GetWorld()->SpawnActor<AFoodBase>(FoodActorClass, FTransform(RandValue), SpawnParameters);
}

void AG_SnakeGameModeBase::CreateFoodActorAfterDestroy()
{
	pSnake = Cast<APlayerPawnBase>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	const auto Snake = Cast<ASnakeBase>(pSnake->SnakeActor);
	if (Snake)
	{
		srand(time(NULL));
		float RandX = 1.01 * (rand() % 700 - 350);
		float RandY = 1.01 * (rand() % 1500 - 700);
		auto RandValue = FVector(RandX, RandY, 0.f);
		if ((RandValue - Snake->SnakeElements[0]->GetActorLocation()).Size() > 200.f)
		{
			FoodActor = GetWorld()->SpawnActor<AFoodBase>(FoodActorClass, FTransform(RandValue));
		}
		else
		{
			CreateFoodActorAfterDestroy();
		}
	}
}

void AG_SnakeGameModeBase::CreateBonus()
{
	//We have some floor paramters: 
	//In rate -350 to 350 on X;
	//In rate -700 to 800 on Y;
	srand(time(NULL));
	float RandX = 1.01 * (rand() % 700 - 350);
	float RandY = 1.01 * (rand() % 1500 - 700);
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	//We spawn Negative/Positive bonus in BonusNegativeClass and BonusPositiveClass
	Spawn = FMath::FRandRange(0, 1);
	if (Spawn >= 0.5)
	{
		BonusActor = GetWorld()->SpawnActor<ABonusBase>(BonusNegativeClass, FTransform(FVector(RandX, RandY, 0.f)),
		                                                SpawnParameters);
	}
	else if (Spawn < 0.5)
	{
		BonusActor = GetWorld()->SpawnActor<ABonusBase>(BonusPositiveClass, FTransform(FVector(RandX, RandY, 0.f)),
		                                                SpawnParameters);
	}
	BonusActor->SetLifeSpan(8.f);
}

void AG_SnakeGameModeBase::CreateTimer()
{
	SpawnDelayRangeLow = 10.0f;
	SpawnDelayRangeHigh = 20.0f;
	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	//We crate new timer after ending previous timer, when we spawn Bonus
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AG_SnakeGameModeBase::CreateBonus, SpawnDelay, true);
}

int32 AG_SnakeGameModeBase::SetScore(int32 Data)
{
	Score += Data;
	UE_LOG(LogAG_SnakeGameModeBase, Display, TEXT("Score: %i"), Score);
	return Score;
}

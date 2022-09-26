// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "G_SnakeGameModeBase.generated.h"

class ASnakeBase;
class AFoodBase;
class APlayerPawnBase;
class ABonusBase;

UCLASS()
class G_SNAKE_API AG_SnakeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	AFoodBase*FoodActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFoodBase> FoodActorClass;

	UPROPERTY(BlueprintReadWrite)
	APlayerPawnBase* pSnake;

	UPROPERTY(BlueprintReadWrite)
	ABonusBase* BonusActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABonusBase> BonusNegativeClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABonusBase> BonusPositiveClass;
	
	float SpawnDelay;
	float DestroyDelay;
	float Spawn;

protected:
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float DestroyDelayRangeLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float DestroyDelayRangeHigh;

public:
	void CreateFoodActor();
	void CreateFoodActorAfterDestroy();
	virtual void CreateBonus();
	void CreateTimer();

	UFUNCTION(BlueprintCallable)
	int32 SetScore(int32 Data);

	UFUNCTION(BlueprintCallable)
	int32 GetScore() { return Score; }

private:
	int32 Score = 0;
};

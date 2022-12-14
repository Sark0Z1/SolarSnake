// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "G_SnakeGameModeBase.h"
#include "GameFramework/Actor.h"
#include "FoodBase.generated.h"

UCLASS()
class G_SNAKE_API AFoodBase : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodBase();

	UPROPERTY(BlueprintReadWrite)
	AG_SnakeGameModeBase*GameMode;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Iteract(AActor* Interactor, bool bIsHead) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnakeElementBase.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.generated.h"

UENUM ()
enum class EMovementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
UCLASS()
class G_SNAKE_API ASnakeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeBase();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASnakeElementBase> SnakeElementClass;

	UPROPERTY()
	TArray<ASnakeElementBase*> SnakeElements;

	UPROPERTY(EditDefaultsOnly)
	float ElementSize;

	UPROPERTY()
	EMovementDirection LastMoveDirection;

	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void AddSnakeElements(int ElementsNum = 1);

	void Move();

	UFUNCTION()
	void SnakeElementOverlap (ASnakeElementBase*OverlappedElement, AActor*Other);

	void IsDead(bool bIsDead); 

};

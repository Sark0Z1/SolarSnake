// Fill out your copyright notice in the Description page of Project Settings.


#include "WallBase.h"
#include "SnakeBase.h"
#include "Snake_PlayerController.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
AWallBase::AWallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

}

// Called when the game starts or when spawned
void AWallBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWallBase::Iteract(AActor* Interactor, bool bIsHead)
{
	IInteractable::Iteract(Interactor, bIsHead);
	const auto Controller = Cast<ASnake_PlayerController>(GetWorld()->GetFirstPlayerController());
	if(!Controller) return;
	auto Snake = Cast<ASnakeBase>(Interactor);
	if (IsValid(Snake))
	{
		Snake->Destroy();
		Controller->IsDead();
	}
}


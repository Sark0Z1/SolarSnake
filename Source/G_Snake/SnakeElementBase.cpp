// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeElementBase.h"
#include "SnakeBase.h"
#include "Snake_PlayerController.h"


ASnakeElementBase::ASnakeElementBase()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
}


void ASnakeElementBase::BeginPlay()
{
	Super::BeginPlay();
}

void ASnakeElementBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASnakeElementBase::SetFirstElementType_Implementation()
{
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ASnakeElementBase::HandleBeginOverlap);
}

void ASnakeElementBase::Iteract(AActor* Interactor, bool bIsHead)
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

void ASnakeElementBase::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                           const FHitResult& SweepResult)
{
	if (IsValid(SnakeOwner))
	{
		SnakeOwner->SnakeElementOverlap(this, OtherActor);
	}
}

void ASnakeElementBase::ToggleCollision()
{
	if (MeshComponent->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
	{
		MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}



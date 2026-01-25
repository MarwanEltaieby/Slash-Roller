// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Slash_Roller/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	FVector startLocation = GetActorLocation();
	FVector endLocation = startLocation + (FVector::ForwardVector * 1000);

	DRAW_SPHERE(GetActorLocation());
	DRAW_LINE(startLocation, endLocation);
	DRAW_POINT(startLocation);
	DRAW_POINT(endLocation);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


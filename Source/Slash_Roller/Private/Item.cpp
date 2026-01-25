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

	AddActorWorldOffset(FVector(0.f, 0.f, 500.f));
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldOffset(FVector(100.f, 0.f, 0.f) * DeltaTime);
	AddActorWorldRotation(FRotator(0.f, 45.f, 0.f) * DeltaTime);
	

	// Debug Drawings
	FVector startLocation = GetActorLocation();
	FVector endLocation = startLocation + (GetActorForwardVector() * 500);

	DRAW_SPHERE_SINGLE_FRAME(GetActorLocation());
	DRAW_LINE_SINGLE_FRAME(startLocation, endLocation);
	DRAW_POINT_SINGLE_FRAME(startLocation);
	DRAW_POINT_SINGLE_FRAME(endLocation);
}


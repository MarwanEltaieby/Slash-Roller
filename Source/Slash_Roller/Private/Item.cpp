// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Slash_Roller/DebugMacros.h"
#include "Components/SphereComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	SetRootComponent(ItemMesh);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->SetupAttachment(GetRootComponent());

	

	ObjectRotation = FRotator(0, 180, 0);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	/*int32 AverageInt = Avg<int32>(1, 3);

	UE_LOG(LogTemp, Warning, TEXT("Average of 1 and 3 is: %d"), AverageInt);

	AddActorWorldOffset(FVector(0.f, 0.f, 500.f));*/

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
}

float AItem::TransformedSin(float Amplitude, float SpeedMultiplier)
{
	return Amplitude * FMath::Sin(RunningTime * SpeedMultiplier);
}

float AItem::TransformedCos(float Amplitude, float SpeedMultiplier)
{
	return Amplitude * FMath::Cos(RunningTime * SpeedMultiplier);
}

void AItem::RotateActor()
{
	AddActorLocalRotation(ObjectRotation * GetWorld()->DeltaTimeSeconds);
}

void AItem::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Other Actor Begin Overlap: %s"), *OtherActor->GetName());
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Other Actor End Overlap: %s"), *OtherActor->GetName());
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	RotateActor();
}


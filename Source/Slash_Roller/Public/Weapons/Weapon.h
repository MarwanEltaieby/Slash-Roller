// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_ROLLER_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	AWeapon();

	void Equip(USceneComponent* SceneComponent, FName SocketName);
	
protected:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};

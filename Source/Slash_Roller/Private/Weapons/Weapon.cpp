// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Weapon.h"
#include "Slash_Roller/Public/Characters/SlashCharacter.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeapon::Equip(USceneComponent* SceneComponent, FName SocketName)
{
	ItemMesh->AttachToComponent(SceneComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

}

void AWeapon::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	//ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);

	//if (SlashCharacter)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Overlapped!"));
	//	PrimaryActorTick.bCanEverTick = false;
	//	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	//	ItemMesh->AttachToComponent(SlashCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Right Hand Socket"));
	//	SlashCharacter->SetWeaponEquipped(true);
	//}

}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

}

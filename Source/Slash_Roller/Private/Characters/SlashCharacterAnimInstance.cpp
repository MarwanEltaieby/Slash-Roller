// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/SlashCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void USlashCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	SlashCharacter = Cast<ASlashCharacter>(TryGetPawnOwner());
	if (SlashCharacter)
	{
		CharacterMovementComponent = SlashCharacter->GetCharacterMovement();
	}
}

void USlashCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	
	if (CharacterMovementComponent)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(CharacterMovementComponent->Velocity);
		isJumping = CharacterMovementComponent->IsFalling();
		isWeaponEquipped = SlashCharacter->GetWeaponEquipped();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "SlashCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_ROLLER_API USlashCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetActionState(EActionStates Value);
	
	UPROPERTY(BlueprintReadOnly)
	class ASlashCharacter* SlashCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class UCharacterMovementComponent* CharacterMovementComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool isJumping;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	ECharacterStates CharacterState;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	EActionStates ActionState;
};

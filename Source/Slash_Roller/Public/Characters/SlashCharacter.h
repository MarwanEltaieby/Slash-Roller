// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class AItem;

UCLASS()
class SLASH_ROLLER_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlashCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Montages")
	UAnimMontage* AttackMontage;

	UCharacterMovementComponent* CharacterMovementComponent;

	void ProcessMovement(const FInputActionValue& Value);
	void ProcessRotating(const FInputActionValue& Value);
	void ProcessJumping(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	void ProcessAttack(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ReEnableInput();

private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* Item;
	
	ECharacterStates CharacterState = ECharacterStates::ECS_UnEquipped;

	EActionStates ActionState = EActionStates::EAS_UnOccupied;

	APlayerController* PlayerController;

public:

	FORCEINLINE AItem* GetItem() const { return Item; }

	FORCEINLINE void SetItem(AItem* Value) { Item = Value; }

	FORCEINLINE ECharacterStates GetCharacterState() const { return CharacterState; }

	FORCEINLINE void GetCharacterState(ECharacterStates Value) { CharacterState = Value; }

	FORCEINLINE EActionStates GetActionState() const { return ActionState; }

	FORCEINLINE void GetActionState(EActionStates Value) { ActionState = Value; }

};

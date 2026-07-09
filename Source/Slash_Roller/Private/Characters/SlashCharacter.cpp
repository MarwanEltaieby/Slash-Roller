// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "InputMappingContext.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Item.h"
#include "Weapons/Weapon.h"

// Sets default values
ASlashCharacter::ASlashCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (Subsystem && CharacterMappingContext)
			{
				Subsystem->AddMappingContext(CharacterMappingContext, 0);
			}
		}
	}
}

// Called every frame
void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("%s"), AttackMontage->IsReadyForFinishDestroy() ? TEXT("True") : TEXT("False"));
	//if (AttackMontage->IsReadyForFinishDestroy)
	//{
	//	EnableInput(PlayerController);
	//}
	//else
	//{
	//	DisableInput(PlayerController);
	//}
}

void ASlashCharacter::ProcessMovement(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator ControlRotation = GetControlRotation();
	const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);
}

void ASlashCharacter::ProcessRotating(const FInputActionValue& Value)
{
	FVector2D RotateVector = Value.Get<FVector2D>();

	AddControllerPitchInput(-RotateVector.Y);
	AddControllerYawInput(RotateVector.X);
}

void ASlashCharacter::ProcessJumping(const FInputActionValue& Value)
{
	Jump();
}

void ASlashCharacter::Interact(const FInputActionValue& Value)
{
	if (AWeapon* Weapon = Cast<AWeapon>(Item))
	{
		Weapon->Equip(GetMesh(), FName("Right Hand Socket"));
		CharacterState = ECharacterStates::ECS_EquippedOneHandedWeapon;
	}
}

void ASlashCharacter::ProcessAttack(const FInputActionValue& Value)
{
	bool AttackValue = Value.Get<bool>();

	UE_LOG(LogTemp, Warning, TEXT("%s"), AttackValue ? TEXT("True") : TEXT("False"));
	if (CharacterState == ECharacterStates::ECS_UnEquipped)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character Does not Equip a weapon"));
	}
	else
	{
		if (ActionState == EActionStates::EAS_UnOccupied)
		{
			PlayAnimMontage(AttackMontage, 1.0f, FName("Attack1"));
			ActionState = EActionStates::EAS_Attacking;
			//DisableInput(PlayerController);
			UE_LOG(LogTemp, Warning, TEXT("Attack!"));
		}
	}
}




// Called to bind functionality to input
void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ASlashCharacter::ProcessMovement);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ASlashCharacter::ProcessRotating);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ASlashCharacter::ProcessJumping);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ASlashCharacter::Interact);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ASlashCharacter::ProcessAttack);
	}
}

void ASlashCharacter::ReEnableInput()
{
	EnableInput(PlayerController);
}


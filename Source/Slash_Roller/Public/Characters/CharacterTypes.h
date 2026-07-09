#pragma once

UENUM(BlueprintType)
enum class ECharacterStates : uint8
{
	ECS_UnEquipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped One-handed Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Equipped two-handed Weapon")
};

UENUM(BlueprintType)
enum class EActionStates : uint8
{
	EAS_UnOccupied UMETA(DisplayName = "Un Occupied"),
	EAS_Attacking UMETA(DisplayName = "Attacking")
};
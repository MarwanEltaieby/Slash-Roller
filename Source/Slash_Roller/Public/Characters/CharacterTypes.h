#pragma once

UENUM(BlueprintType)
enum class ECharacterStates : uint8
{
	ECS_UnEquipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped One-handed Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Equipped two-handed Weapon")
};
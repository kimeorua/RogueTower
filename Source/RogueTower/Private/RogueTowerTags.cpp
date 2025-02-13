// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueTowerTags.h"

namespace RogueTowerTag
{
	/*Input Tag*/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move_Forward, "InputTag.Move.Forward");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move_Back, "InputTag.Move.Back");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move_Left, "InputTag.Move.Left");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move_Right, "InputTag.Move.Right");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Dash, "InputTag.Dash");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");

	/*Player Tag*/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_GreateSword, "Player.Weapon.GreateSword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_DualBlade, "Player.Weapon.DualBlade");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Katana, "Player.Weapon.Katana");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Dash, "Player.Ability.Dash");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Jump, "Player.Ability.Jump");
}
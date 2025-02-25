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
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ComboAttack, "InputTag.ComboAttack");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold, "InputTag.Hold");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_Dash, "InputTag.Hold.Dash");
	

	/*Player Tag*/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_GreateSword, "Player.Weapon.GreateSword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_DualBlade, "Player.Weapon.DualBlade");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Katana, "Player.Weapon.Katana");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Dash, "Player.Ability.Dash");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Jump, "Player.Ability.Jump");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ComboAttack, "Player.Ability.ComboAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ComboAttack_1, "Player.Ability.ComboAttack.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ComboAttack_2, "Player.Ability.ComboAttack.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ComboAttack_3, "Player.Ability.ComboAttack.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_ComboAttack_4, "Player.Ability.ComboAttack.4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_DrawUI, "Player.Ability.DrawUI");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_JumpEnd, "Player.Event.JumpEnd");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ComboWindowOpen, "Player.Event.ComboWindowOpen");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ComboWindowClose, "Player.Event.ComboWindowClose");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Jumpping, "Player.Status.Jumpping");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyNextCombo, "Player.Status.ReadyNextCombo");

	/*Shared Tag*/
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueTowerTags.h"

namespace RogueTowerTag
{
	/*Input Tag*/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move_Forward, "InputTag.Move.Forward");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move_Right, "InputTag.Move.Right");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ComboAttack, "InputTag.ComboAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Avoid, "InputTag.Avoid");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold, "InputTag.Hold");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_Dash, "InputTag.Hold.Dash");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Hold_LockOn, "InputTag.Hold.LockOn");
	

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
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_LockOn, "Player.Ability.LockOn");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Avoid, "Player.Ability.Avoid");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_JumpEnd, "Player.Event.JumpEnd");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ComboWindowOpen, "Player.Event.ComboWindowOpen");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ComboWindowClose, "Player.Event.ComboWindowClose");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_AvoidStart, "Player.Event.AvoidStart");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_AvoidEnd, "Player.Event.AvoidEnd");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_MoveForward, "Player.Status.MoveForward");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_MoveRight, "Player.Status.MoveRight");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Jumpping, "Player.Status.Jumpping");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyNextCombo, "Player.Status.ReadyNextCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_UseLockOn, "Player.Status.UseLockOn");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Avoid, "Player.Status.Avoid");

	/*Shared Tag*/
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Death, "Shared.Status.Death");

	/*Enemy Tag*/
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_MeleeAttack, "Enemy.Ability.MeleeAttack");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_MiddleRangeAttack, "Enemy.Ability.MidleeRangeAttack");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Event_AbilityEnd, "Enemy.Event.AbilityEnd");
}
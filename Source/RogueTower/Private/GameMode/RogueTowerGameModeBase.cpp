// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/RogueTowerGameModeBase.h"
#include "Stage/StageManager.h"

AStageManager* ARogueTowerGameModeBase::GetStageManager() const
{
	AStageManager* StageManager = AStageManager::Get(GetWorld());
	if (StageManager)
	{
		return StageManager;
	}
	else
	{
		return nullptr;
	}
}
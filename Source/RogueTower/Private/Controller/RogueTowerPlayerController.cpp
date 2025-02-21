// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/RogueTowerPlayerController.h"

ARogueTowerPlayerController::ARogueTowerPlayerController()
{
    PlayerTeamID = FGenericTeamId(0);
}

FGenericTeamId ARogueTowerPlayerController::GetGenericTeamId() const
{
    return PlayerTeamID;
}

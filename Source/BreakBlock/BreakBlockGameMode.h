// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BreakBlockGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BREAKBLOCK_API ABreakBlockGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
	
	ABreakBlockGameMode();

};

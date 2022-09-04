// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerUIMain_UW.generated.h"

/**
 * 
 */
UCLASS()
class ELDENRING_API UPlayerUIMain_UW : public UUserWidget
{
	GENERATED_BODY()
	
		UPROPERTY(Meta = (BindWidget))
		class UPlayerUI_UW* PlayerUI_WB;


public:
	void SetPlayerHP(float fCurrent);
	void SetPlayerMP(float fCurrent);
	void SetPlayerStamina(float fCurrent);
	void SetMonsterHP(float fCurrent);
	void SetMonsterName(FString MonsterName);
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "StringGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_BASICPRACTICE_API UStringGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
	
private:
	
};

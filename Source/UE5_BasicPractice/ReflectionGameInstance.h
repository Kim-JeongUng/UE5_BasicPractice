// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ReflectionGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_BASICPRACTICE_API UReflectionGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UReflectionGameInstance();
	virtual void Init() override;
	
private:
	UPROPERTY()
	FString SchoolName;
};

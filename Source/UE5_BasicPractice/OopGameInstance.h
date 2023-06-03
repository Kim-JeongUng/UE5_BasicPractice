// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OopGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_BASICPRACTICE_API UOopGameInstance : public UGameInstance
{
	
	GENERATED_BODY()
	
public:
	UOopGameInstance();
	virtual void Init() override;
	
private:
	UPROPERTY()
	TObjectPtr<class UCourseInfo> CourseInfo;
	
	UPROPERTY()
	FString SchoolName;
};

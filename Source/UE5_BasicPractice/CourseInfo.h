// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CourseInfo.generated.h" 

DECLEARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangeSignature, const FString&, const FString&);

/**
 * 
 */
UCLASS()
class UE5_BASICPRACTICE_API UCourseInfo : public UObject
{
	GENERATED_BODY()

public:
	UCourseInfo();

	FCourseInfoOnChangeSignature OnChanged;

	void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents);

private:
	FString Contents;
};

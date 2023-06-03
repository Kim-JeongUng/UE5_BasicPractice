// Fill out your copyright notice in the Description page of Project Settings.


#include "CourseInfo.h"

UCourseInfo::UCourseInfo()
{
	Contents = TEXT("기존 학사 정보");
}
void UCourseInfo ::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents)
{
	Contents = InNewContents;
	
	UE_LOG(LogTemp, Log, TEXT("[CourseInfol 학사 정보가 변경되어 암림을 발송함니다."));
	OnChanged.Broadcast(InSchoolName, Contents) ;
};
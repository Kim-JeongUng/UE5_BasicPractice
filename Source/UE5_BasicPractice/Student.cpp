// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("학생1");
	Year = 1;
	Id = 1;
}

void UStudent::DoLesson()
{
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%d학년 %d번 %s님이 수업을 듣습니다."), Year, Id, *Name);
}

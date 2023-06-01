// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"

#include "Card.h"


UTeacher::UTeacher()
{
	Name = TEXT("선생1");
	Year = 3;
	Id = 1;
	Card -> SetCardType(ECardType::Teacher);
}

void UTeacher::DoLesson()
{
	ILessonInterface::DoLesson();

	UE_LOG(LogTemp, Log, TEXT("%d년차 %s님이 수업을 합니다."), Year, *Name);
}

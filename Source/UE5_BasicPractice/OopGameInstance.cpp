// Fill out your copyright notice in the Description page of Project Settings.


#include "OopGameInstance.h"

#include "CourseInfo.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"


UOopGameInstance::UOopGameInstance()
{
	SchoolName = TEXT("학교");
}

void UOopGameInstance::Init()
{
	Super::Init();

	CourseInfo = NewObject<UCourseInfo>();
	
	UE_LOG(LogTemp, Log, TEXT("==========================="));
	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>() };
	for(const auto Person : Persons)
	{
		const UCard* OwnCard =Person->GetCard();
		ECardType CardType = OwnCard->GetCardType();
		//UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드의 종류: %d"),*Person->GetName(), CardType);

		const UEnum* CardEnumType = FindObject<UEnum>(nullptr,TEXT("/Script/UE5_BasicPractice.ECardType"));
		if(CardEnumType)
		{
		   FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
		   UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드의 종류: %s"),*Person->GetName(), *CardMetaData);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("==========================="));

	for(const auto Person : Persons)
	{
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if(LessonInterface)
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 있습니다."),*Person->GetName());
			LessonInterface->DoLesson();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 없습니다."),*Person->GetName());
		}
	}
	UE_LOG(LogTemp, Log, TEXT("==========================="));

	UStudent* Student1 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));
	UStudent* Student2 = NewObject<UStudent>();
	Student2->SetName(TEXT("학생2"));
	UStudent* Student3 = NewObject<UStudent>();
	Student3->SetName(TEXT("학생3"));

	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);

	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));
	UE_LOG(LogTemp, Log, TEXT("==========================="));
	
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "OopGameInstance.h"

#include "Staff.h"
#include "Student.h"
#include "Teacher.h"


UOopGameInstance::UOopGameInstance()
{
	SchoolName = TEXT("기본 학교");
}

void UOopGameInstance::Init()
{
	Super::Init();
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

	
}
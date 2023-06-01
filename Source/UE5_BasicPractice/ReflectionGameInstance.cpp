// Fill out your copyright notice in the Description page of Project Settings.


#include "ReflectionGameInstance.h"

#include "Staff.h"
#include "Student.h"
#include "Teacher.h"

UReflectionGameInstance::UReflectionGameInstance()
{
	SchoolName = TEXT("기본 학교");
}

void UReflectionGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Log, TEXT("==========================="));
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UReflectionGameInstance ::StaticClass();
	//check(ClassRuntime == ClassCompile);
	ensure(ClassRuntime == ClassCompile);
	
	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName());

	SchoolName = TEXT("다음 학교");
	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값 : %s"), *GetClass()->GetDefaultObject<UReflectionGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("==========================="));

	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();

	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 : %s"),*Student->GetName());

	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("김정웅"));
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if(NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 : %s"),*CurrentTeacherName);
		
		NameProp->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 : %s"),*Teacher->GetName());
	}
	UE_LOG(LogTemp, Log, TEXT("==========================="));

	Student->DoLesson();
	UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	if(DoLessonFunc)
	{
		Teacher->ProcessEvent(DoLessonFunc,nullptr);
	}
	UE_LOG(LogTemp, Log, TEXT("==========================="));
	

}

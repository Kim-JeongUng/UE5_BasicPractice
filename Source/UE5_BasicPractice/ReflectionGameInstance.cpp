// Fill out your copyright notice in the Description page of Project Settings.


#include "ReflectionGameInstance.h"

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
}

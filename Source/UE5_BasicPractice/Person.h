// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class UE5_BASICPRACTICE_API UPerson : public UObject
{
	
	GENERATED_BODY()
	
public:
	UPerson();
	
	UFUNCTION()

	FORCEINLINE FString& GetName() {return Name;}
	FORCEINLINE void SetName(const FString& InName) {Name = InName;}

	FORCEINLINE class UCard* GetCard() const {return Card;}
	FORCEINLINE void SetCard(class UCard* InCard){Card = InCard;}
	
protected:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Year;

	UPROPERTY()
	TObjectPtr<class UCard> Card;

	
private:
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyIDPluginGameInstanceSubsystem.generated.h"

UCLASS()
class NBC_USERPLUGIN_API UMyIDPluginGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UMyIDPluginGameInstanceSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	//UFUNCTION(BlueprintCallable, Category = "GameInstanceTEST")
	void SetUserName(const FString& NewUserName);
	//UFUNCTION(BlueprintCallable, Category = "GameInstanceTEST")
	FString GetUserName();

private:
	FString UserName;
	
};

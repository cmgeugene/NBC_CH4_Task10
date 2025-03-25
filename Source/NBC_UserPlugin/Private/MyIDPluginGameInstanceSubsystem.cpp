// Fill out your copyright notice in the Description page of Project Settings.


#include "MyIDPluginGameInstanceSubsystem.h"

UMyIDPluginGameInstanceSubsystem::UMyIDPluginGameInstanceSubsystem()
{
	UserName = TEXT("GUEST2");
	UE_LOG(LogTemp, Warning , TEXT("[Constructor] Username set to : %s"), *UserName);
}

void UMyIDPluginGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UserName = TEXT("GUEST1");
	UE_LOG(LogTemp, Warning, TEXT("[Initilaizer] Username set to : %s"), *UserName);
}

void UMyIDPluginGameInstanceSubsystem::SetUserName(const FString& NewName)
{
	UserName = NewName;
	UE_LOG(LogTemp, Log, TEXT("[GameInstance] UserName set to : %s"), *UserName);
}
FString UMyIDPluginGameInstanceSubsystem::GetUserName()
{
	return UserName;
}


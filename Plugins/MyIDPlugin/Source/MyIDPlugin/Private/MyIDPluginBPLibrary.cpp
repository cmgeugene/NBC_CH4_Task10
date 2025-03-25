// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyIDPluginBPLibrary.h"
#include "MyIDPlugin.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "../../../Source/NBC_UserPlugin/Public/MyIDPluginGameInstanceSubsystem.h"


FString UMyIDPluginBPLibrary::UserName = TEXT("Unknown");

UMyIDPluginBPLibrary::UMyIDPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UMyIDPluginBPLibrary::SetUserName(const FString& NewName)
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GEngine->GameViewport->GetGameInstance());
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameInstance is null.")); 
		return;
	}
	UMyIDPluginGameInstanceSubsystem* MySubsystem = GameInstance->GetSubsystem<UMyIDPluginGameInstanceSubsystem>();
	if (MySubsystem)
	{
		MySubsystem->SetUserName(NewName);
	}
	
}
FString UMyIDPluginBPLibrary::GetUserName()
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GEngine->GameViewport->GetGameInstance());
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameInstance is null."));
		return TEXT("ERROR");
	}
	UMyIDPluginGameInstanceSubsystem* MySubsystem = GameInstance->GetSubsystem<UMyIDPluginGameInstanceSubsystem>();
	if (MySubsystem)
	{
		return MySubsystem->GetUserName();
	}
	return TEXT("ERROR");
}


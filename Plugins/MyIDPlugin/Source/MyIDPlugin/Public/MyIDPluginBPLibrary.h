// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyIDPluginBPLibrary.generated.h"

UCLASS()
class UMyIDPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyIDPlugin")
	static void SetUserName(const FString& NewName);
	UFUNCTION(BlueprintCallable, Category = "MyIDPlugin")
	static FString GetUserName();

private:
	static FString UserName;
};

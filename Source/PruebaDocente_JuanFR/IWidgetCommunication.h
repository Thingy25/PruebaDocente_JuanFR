// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IWidgetCommunication.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BLUEPRINTABLE)
class UIWidgetCommunication : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PRUEBADOCENTE_JUANFR_API IIWidgetCommunication
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EnablePromptWidget(const FString& Prompt);
};

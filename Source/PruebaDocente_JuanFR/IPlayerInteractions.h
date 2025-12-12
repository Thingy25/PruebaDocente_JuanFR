// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerInteractions.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIPlayerInteractions : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PRUEBADOCENTE_JUANFR_API IIPlayerInteractions
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PlayInteractAnimation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StopLoopingAnimation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartLoopingAnimation();
};

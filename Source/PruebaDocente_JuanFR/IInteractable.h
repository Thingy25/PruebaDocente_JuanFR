// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IInteractable.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class UInteractable : public UInterface {
	GENERATED_BODY()

};
class PRUEBADOCENTE_JUANFR_API IInteractable
{
	GENERATED_IINTERFACE_BODY()
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteract(APawn* InteractorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractionStart(APawn* InteractorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractionStop(APawn* InteractorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FString GetInteractionPromptText() const;

	/*UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteract(APawn* InteractorPawn);
	virtual void OnInteract_Implementation(APawn* InteractorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractionStart(APawn* InteractorPawn);
	virtual void OnInteractionStart_Implementation(APawn* InteractorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractionStop(APawn* InteractorPawn);
	virtual void OnInteractionStop_Implementation(APawn* InteractorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FString GetInteractionPromptText() const;
	virtual FString GetInteractionPromptText_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EnablePromptWidget(const FString& Prompt);
	virtual void EnablePromptWidget_Implementation(const FString& Prompt);*/
};

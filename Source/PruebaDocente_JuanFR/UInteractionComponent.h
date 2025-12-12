// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "UInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBADOCENTE_JUANFR_API UUInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FTimerHandle DetectionTimerHandle;

	AActor* ActorToInteract = nullptr;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float TimerRate = 0.1f;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float ObjectDetectionRadius = 0;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float DetectionSphereOffset = 0;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Interaction")
	TObjectPtr<UWidgetComponent> TextPromptWidget;

	UFUNCTION()
	void TryGetInteractable();


public:	
	UFUNCTION(BlueprintCallable)
	void RequestInteractionStart();

	UFUNCTION(BlueprintCallable)
	void RequestInteractionStop();


		
};

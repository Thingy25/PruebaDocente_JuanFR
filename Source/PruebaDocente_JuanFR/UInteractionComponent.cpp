// Fill out your copyright notice in the Description page of Project Settings.


#include "UInteractionComponent.h"
#include "TimerManager.h" //!!!!!!!!!!!!!!!!
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "IInteractable.h"
#include "IWidgetCommunication.h"

// Sets default values for this component's properties
UUInteractionComponent::UUInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UUInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(DetectionTimerHandle, this, &UUInteractionComponent::TryGetInteractable, TimerRate, true);
	TextPromptWidget = GetOwner()->FindComponentByClass<UWidgetComponent>();

	// ...
	
}


// Called every frame
//void UUInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UUInteractionComponent::TryGetInteractable() {
	

		FHitResult OutHit;
		FVector TraceStart = (GetOwner()->GetActorForwardVector() * DetectionSphereOffset) + GetOwner()->GetActorLocation();//GetOwner()->GetActorLocation() + DetectionSphereOffset;
		FVector TraceEnd = TraceStart;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(GetOwner());
		bool bHit = GetWorld()->SweepSingleByChannel(OutHit, TraceStart, TraceEnd, FQuat::Identity, ECC_Pawn, FCollisionShape::MakeSphere(ObjectDetectionRadius), CollisionParams
	);
		//DrawDebugSphere(GetWorld(), TraceStart, ObjectDetectionRadius, 12, FColor::Red, false, 5);

		if (bHit && OutHit.GetActor()->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{

			ActorToInteract = OutHit.GetActor();

			//DrawDebugSphere(GetWorld(), TraceStart, ObjectDetectionRadius, 12, FColor::Green, false, 5);

			FString Prompt = IInteractable::Execute_GetInteractionPromptText(OutHit.GetActor());

			UUserWidget* PromptWidget = TextPromptWidget->GetUserWidgetObject();
			if (PromptWidget->GetClass()->ImplementsInterface(UIWidgetCommunication::StaticClass()))
			{
				IIWidgetCommunication::Execute_EnablePromptWidget(PromptWidget, Prompt);
			}

			//IInteractable::Execute_EnablePromptWidget(OutHit.GetActor(), Prompt, true);

			TextPromptWidget->SetVisibility(true);

			//UKismetSystemLibrary::PrintString(
			//	GetWorld(), // Or any valid UObject* that can provide a world context
			//	TEXT("WORKING"),
			//	true, // bPrintToScreen
			//	true, // bPrintToLog
			//	FLinearColor::Blue,
			//	5.0f, // Duration in seconds
			//	NAME_None); // Key (optional, for updating same message)
		}
		else {
			TextPromptWidget->SetVisibility(false);

			ActorToInteract = nullptr;
		}

}

void UUInteractionComponent::RequestInteractionStart() {

	if (ActorToInteract)
	{
		IInteractable::Execute_OnInteract(ActorToInteract, UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	}
}

void UUInteractionComponent::RequestInteractionStop() {
	UKismetSystemLibrary::PrintString(
		GetWorld(), // Or any valid UObject* that can provide a world context
		TEXT("STOP"),
		true, // bPrintToScreen
		true, // bPrintToLog
		FLinearColor::Green,
		5.0f, // Duration in seconds
		NAME_None); // Key (optional, for updating same message)
}


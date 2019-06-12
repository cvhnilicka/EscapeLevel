// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYLEVELESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Handle the event to trigger the blueprint to open the door
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpenRequst;

	// Handle the event to trigger the blueprint to close the door
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnCloseRequest;


private: 
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;  // for type checking to prevent crashes

	AActor* Owner; 

	// Function to get the total mass of the actors on the pressure plate
	float GetTotalMassOfActorsOnPlate();

	UPROPERTY(EditAnywhere)
		float TriggerMass = 5.f;

		
};

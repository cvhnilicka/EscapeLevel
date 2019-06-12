// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "FinalDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinalDoor);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYLEVELESCAPE_API UFinalDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFinalDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Handle the event to trigger the blueprint to open the door
	UPROPERTY(BlueprintAssignable)
		FFinalDoor OnOpenRequst;

	// Handle the event to trigger the blueprint to close the door
	UPROPERTY(BlueprintAssignable)
		FFinalDoor OnCloseRequest;

private:
	UPROPERTY(EditAnywhere)
		float TriggerMass = 3.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* Room1 = nullptr;  // for type checking to prevent crashes

	UPROPERTY(EditAnywhere)
		ATriggerVolume* Room2 = nullptr;  // for type checking to prevent crashes

	UPROPERTY(EditAnywhere)
		ATriggerVolume* Room3 = nullptr;  // for type checking to prevent crashes

	UPROPERTY(EditAnywhere)
		ATriggerVolume* Room4 = nullptr;  // for type checking to prevent crashes
		

	AActor* Owner;

	// Function to get the total mass of the actors on the pressure plate
	float GetTotalMassOfActorsOnPlate(ATriggerVolume* plate);

	bool isopen = false;

};

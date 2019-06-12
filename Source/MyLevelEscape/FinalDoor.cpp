// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalDoor.h"

// Sets default values for this component's properties
UFinalDoor::UFinalDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFinalDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();

	if (!Room1)
	{
		UE_LOG(LogTemp, Error, TEXT("%s room1"), *GetOwner()->GetName())
	}
	if (!Room2)
	{
		UE_LOG(LogTemp, Error, TEXT("%s room2"), *GetOwner()->GetName())
	}
	if (!Room3)
	{
		UE_LOG(LogTemp, Error, TEXT("%s room3"), *GetOwner()->GetName())
	}
	if (!Room4)
	{
		UE_LOG(LogTemp, Error, TEXT("%s room4"), *GetOwner()->GetName())
	}

	// ...
	
}


// Called every frame
void UFinalDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(GetTotalMassOfActorsOnPlate(Room1) > TriggerMass &&
		GetTotalMassOfActorsOnPlate(Room2) > TriggerMass &&
		GetTotalMassOfActorsOnPlate(Room3) > TriggerMass && 
		GetTotalMassOfActorsOnPlate(Room4) > TriggerMass)
	{
		UE_LOG(LogTemp, Error, TEXT("OPEN3"))
		OnOpenRequst.Broadcast();
		isopen = true;
	} 

	// ...
}

float UFinalDoor::GetTotalMassOfActorsOnPlate(ATriggerVolume* plate)
{
	float TotalMass = 0.f;
	if (!plate) { return TotalMass; }  // validate

	/// find all of the overlapping actors
	TArray<AActor*> OverLappingActors;
	plate->GetOverlappingActors(OUT OverLappingActors);

	/// Iterate through and add up their masses
	for (const auto* Actor : OverLappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}
	return TotalMass;
}


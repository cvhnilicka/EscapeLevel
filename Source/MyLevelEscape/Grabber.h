// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYLEVELESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-Cast and grab whats in reach
	void Grab();

	// Release Object
	void Release();

	// Find Physics handlecomponent
	void FindPhysicsHandleComponent();

	// Find Input Component (assumed)
	void FindInputComponent();

	// Return Hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Return the current end of the reach line
	FVector GetReachLineEnd();

	// Returns the current end of the reach line
	FVector GetReachLineStart();



		
};

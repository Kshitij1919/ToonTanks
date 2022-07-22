// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "Movable_Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AMovable_Tower : public ATower
{
	GENERATED_BODY()
	public:
		virtual void Tick(float DeltaTime)override;
	protected:
	// Called when the game starts
		virtual void BeginPlay() override;
	
	private:
		UPROPERTY(EditAnywhere)
		FVector MoveLocation;
		UPROPERTY(EditAnywhere)
		float Speed;
		FVector InitialLocation;
	
};

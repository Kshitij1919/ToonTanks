// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;


	private:

		void Move(float value);

		void Turn(float value);

		UPROPERTY(EditAnywhere ,Category = "Movement")
		float TurnRate = 0.0f;

		UPROPERTY(EditAnywhere ,Category = "Movement")
		float Speed = 0.0f; 

		UPROPERTY(VisibleAnywhere, Category = "Component")
		class UCameraComponent* Camera;

		UPROPERTY(VisibleAnywhere, Category = "Component"/*, meta = (AllowPrivateAccess = "true")*/)
		class USpringArmComponent* SpringArm;


	APlayerController* TankPlayerController;

	public:
		ATank();

		void HandleDestruction();
		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

			
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		 APlayerController* GetTankPlayerController()const{return TankPlayerController;}

	 
		bool bAlive = true;
};

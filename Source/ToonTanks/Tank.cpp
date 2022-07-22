// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"


ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);



}

void ATank::HandleDestruction()
 {
     Super::HandleDestruction();
     SetActorHiddenInGame(true);
     SetActorTickEnabled(false);
     bAlive = false;
 }


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

    TankPlayerController =  Cast<APlayerController>(GetController()) ;
	
    
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(TankPlayerController)
    {
        FHitResult HitResult;
        TankPlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, 
        false,
        HitResult
        );


        /*DrawDebugSphere(
        GetWorld(),
        HitResult.ImpactPoint,
        20.0f,
        12,
        FColor::Red,
        false,
        -1.0f
        );*/

        RotateTurret(HitResult.ImpactPoint);




    }

}



void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"),this, &ATank::Turn);
    PlayerInputComponent->BindAction(TEXT("Fire"),IE_Pressed,this, & ATank::Fire);
}

void ATank::Move(float value)
{
   // UE_LOG(LogTemp, Warning, TEXT(" Value: %f"), value);
    FVector Deltalocation(0.0f);
    Deltalocation.X = value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
     AddActorLocalOffset(Deltalocation, true);
}

void ATank::Turn(float value)
{
   FRotator DeltaRotation(0.0f);
   DeltaRotation.Yaw = value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
   AddActorLocalRotation(DeltaRotation,true);
}


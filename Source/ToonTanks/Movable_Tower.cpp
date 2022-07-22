// Fill out your copyright notice in the Description page of Project Settings.


#include "Movable_Tower.h"
#include "Kismet/GameplayStatics.h"

void AMovable_Tower::BeginPlay()
{
    Super::BeginPlay();
    InitialLocation = this->GetActorLocation();
}

void AMovable_Tower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    /*if (InFireRange())
    {
       //CheckFireCondition();
         MoveLocation.Y  = Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
        int LocationDiffrence = this->GetActorLocation().Y - InitialLocation.Y;
        if ( LocationDiffrence >=500 || LocationDiffrence <= 500 )
        {
            UE_LOG(LogTemp, Warning, TEXT("%f"),this->GetActorLocation().Y);
            MoveLocation.Y  *=  -1;
            InitialLocation =  this->GetActorLocation();
        }
        
       
        AddActorLocalOffset(MoveLocation);
    }*/
    

}
// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter_GameMode.h"
#include "GameFramework/Actor.h"


AMainCharacter_GameMode::AMainCharacter_GameMode()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMainCharacter_GameMode::BeginPlay()
{
    Super::BeginPlay();

    FTimerHandle UnusedHandle;
    GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMainCharacter_GameMode::SpawnPlayerRecharge, FMath::RandRange(2, 5), true);
}

void AMainCharacter_GameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMainCharacter_GameMode::SpawnPlayerRecharge()
{
    float randomX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
    float randomY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

    FVector SpawnPosition = FVector(randomX, randomY, Spawn_Z);
    FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

    GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}

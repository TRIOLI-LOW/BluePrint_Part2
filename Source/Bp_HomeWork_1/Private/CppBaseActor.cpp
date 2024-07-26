// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

int ACppBaseActor::countName = 0;

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsAlive = true;
	EnemyNum = 10;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);


}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	PlayerName = FString::Printf(TEXT("A_CppBase_C_%d"), ACppBaseActor::countName++);

	InitialLocation = GetActorLocation();
	
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SinMovement();
}
void ACppBaseActor::SinMovement() {

	float Time = GetWorld()->GetTimeSeconds();
	float SinValue = FMath::Sin(Time * Frequency) * Amplitude;
	FVector NewLocation = InitialLocation;
	NewLocation.Z += SinValue;
	SetActorLocation(NewLocation);
}

void ACppBaseActor::ShowInformation()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerName: %s"), *PlayerName);
	UE_LOG(LogTemp, Warning, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Warning, TEXT("IsAlive: %d"), IsAlive);

}


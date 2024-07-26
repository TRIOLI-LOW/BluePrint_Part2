// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor;

UCLASS()
class BP_HOMEWORK_1_API ACppHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f;

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	const int32 TotalCount = 10; // максимально колличество срабатывания таймера
	int32 CurrentTimerCount = 0; // текущее число срабатываний
	// Called every frame

	UPROPERTY()
	TArray<ACppBaseActor*> SpawnedObjects;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor> CppClass;


	virtual void Tick(float DeltaTime) override;

	void OnTimeToSpawn();
	void OnTimeToDestroy();
};

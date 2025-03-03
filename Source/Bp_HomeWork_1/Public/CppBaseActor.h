
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotator = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class BP_HOMEWORK_1_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	UFUNCTION(BlueprintCallable)
	void SinMovement();

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0f;
	UPROPERTY(EditAnywhere)
	float Frequency = 70.0f;





	UPROPERTY(VisibleAnywhere)
	FString PlayerName;
	UPROPERTY(EditAnywhere)
	int EnemyNum;
	UPROPERTY(EditInstanceOnly)
	bool IsAlive;
    
	static int countName ;
private: 
	FVector InitialLocation;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

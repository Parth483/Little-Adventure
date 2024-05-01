// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "MovingPlatform.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);
UCLASS()


class LEARNING_KIT_API AMovingPlatform : public AActor
{


	GENERATED_BODY()
	

	

public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	////for Moving direction
	//for start location
	FVector StartActorLocation;
	
	//enableing move
	UPROPERTY(EditAnyWhere, Category = "MoveingPlatform")
	bool MoveEnable = true;

	//for offset
	UPROPERTY(EditAnywhere, Category = "MoveingPlatform")
	FVector MoveOffset;

	FVector MoveOffsetNorm;

	//spped
	UPROPERTY(EditAnyWhere, Category = "MoveingPlatform")
	float Speed = 1.f;

	//max Distance and currnt distance
	float CurDistance = 0.0f;

	UPROPERTY(EditAnyWhere, Category = "MoveingPlatform")
	float maxDistance = 0.0f;

	//move Direction
	int movedirection = 1;


	//for rotations

	

	UPROPERTY(EditAnywhere,Category="Rotation Platform")
	FRotator RotationVelocity;

	

	






private:

	//for movement
	UFUNCTION(BlueprintCallable)
	void MovePlatform(float Delta);

	UFUNCTION(BlueprintCallable)
	void RotatePlatform(float Delta);

	
	

	

};

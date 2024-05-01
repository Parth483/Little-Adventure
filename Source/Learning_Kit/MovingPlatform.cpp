// Fill out your copyright notice in the Description page of Project Settings.
#include "MovingPlatform.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	

	//get actor location
	StartActorLocation = GetActorLocation();
	//settting the offsets
	MoveOffsetNorm = MoveOffset;
	MoveOffsetNorm.Normalize();

	//setting tick function to Moveenable
	SetActorTickEnabled(MoveEnable);


	//get a name of all the actors
	FString Name = GetName();

	UE_LOG(LogTemplateCharacter, Display, TEXT("Begin Play: %s"),*Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//using seprate function
	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
	
	//setting new actor location
	SetActorLocation(StartActorLocation + MoveOffsetNorm * CurDistance);
	

}

void AMovingPlatform::MovePlatform(float Delta)
{
	//if move enable call this
	if (MoveEnable)
	{
		//changing currnt direction
		CurDistance += Delta * Speed * movedirection;

		//cheacking if its reach max distance change the direction
		if (CurDistance >= maxDistance || CurDistance <= 0.0f)
		{
			movedirection *= -1;
		}
	}
}

void AMovingPlatform::RotatePlatform(float Delta)
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * Delta;
	SetActorRotation(CurrentRotation);

	AddActorLocalRotation(RotationVelocity * Delta);
}



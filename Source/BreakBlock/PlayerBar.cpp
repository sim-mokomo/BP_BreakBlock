// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBar.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Engine/World.h"
#include "Engine/Classes/Components/InputComponent.h"

// Sets default values
APlayerBar::APlayerBar()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	barMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarMesh"));
	RootComponent = barMesh;

}

void APlayerBar::MoveHorizontal(float AxisValue)
{

	FVector deltaLoc = AxisValue * GetActorRightVector() * GetWorld()->GetTimeSeconds() * this->moveSpeed;
	AddActorWorldOffset(deltaLoc, true);

}

// Called when the game starts or when spawned
void APlayerBar::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerBar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

// Called to bind functionality to input
void APlayerBar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &APlayerBar::MoveHorizontal);
}


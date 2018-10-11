// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBall.h"
#include "PlayerBall.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Engine/Classes/Engine/Engine.h"

// Sets default values
APlayerBall::APlayerBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = ballMesh;

	ballMesh->OnComponentHit.AddDynamic(this, &APlayerBall::OnBallHitEvent);

}

void APlayerBall::SetMoveDirection(FVector newMoveDirection)
{
	this->moveDirection = newMoveDirection;
}

void APlayerBall::OnBallHitEvent(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	this->moveDirection = UKismetMathLibrary::MirrorVectorByNormal(this->moveDirection, Hit.Normal);
}

// Called when the game starts or when spawned
void APlayerBall::BeginPlay()
{
	Super::BeginPlay();
	
	this->moveDirection = (GetActorForwardVector() + GetActorRightVector());
}

// Called every frame
void APlayerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector moveDeltaLoc = this->moveDirection * moveSpeed * DeltaTime;
	AddActorWorldOffset(moveDeltaLoc, true);

}


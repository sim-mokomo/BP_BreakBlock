// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "PlayerBall.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	blockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = blockMesh;

	blockMesh->OnComponentHit.AddDynamic(this, &ABlock::OnBlockHitEvent);
}

void ABlock::OnBlockHitEvent(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	APlayerBall* hitPlayerBall = Cast<APlayerBall>(OtherActor);
	if (hitPlayerBall)
	{

		UWorld* world = GetWorld();
		FTransform spawnTrans;
		spawnTrans.SetLocation(GetActorLocation());
		UGameplayStatics::SpawnEmitterAtLocation(world, destroyParticle,spawnTrans);
		
		Destroy();
	}
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


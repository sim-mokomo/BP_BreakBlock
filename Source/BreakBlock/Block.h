// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class BREAKBLOCK_API ABlock : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* blockMesh;

	/* 破壊時パーティクルです */
	UPROPERTY(EditAnywhere)
		class UParticleSystem* destroyParticle;

public:	
	// Sets default values for this actor's properties
	ABlock();

	/* 何かしらにヒットしたときに実行されるイベントです。ボールに当たった時に破壊されるために使用しています。 */
	UFUNCTION()
	void OnBlockHitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

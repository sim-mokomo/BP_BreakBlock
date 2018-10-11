// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBall.generated.h"

UCLASS()
class BREAKBLOCK_API APlayerBall : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* ballMesh;
	
	/* 移動の方向を表しています */
	UPROPERTY()
	FVector moveDirection;

	/* 移動速度を表しています */
	UPROPERTY(EditAnywhere)
		float moveSpeed = 500.0f;

public:	
	// Sets default values for this actor's properties
	APlayerBall();

	/* 移動の方向を newMoveDirection方向に 書き換えます */
	UFUNCTION()
		void SetMoveDirection(FVector newMoveDirection);

	/* 何かしらにヒットしたときに発生するイベントです。反射の実装に使用されています */
	UFUNCTION()
		void OnBallHitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

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
	
	/* �ړ��̕�����\���Ă��܂� */
	UPROPERTY()
	FVector moveDirection;

	/* �ړ����x��\���Ă��܂� */
	UPROPERTY(EditAnywhere)
		float moveSpeed = 500.0f;

public:	
	// Sets default values for this actor's properties
	APlayerBall();

	/* �ړ��̕����� newMoveDirection������ ���������܂� */
	UFUNCTION()
		void SetMoveDirection(FVector newMoveDirection);

	/* ��������Ƀq�b�g�����Ƃ��ɔ�������C�x���g�ł��B���˂̎����Ɏg�p����Ă��܂� */
	UFUNCTION()
		void OnBallHitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

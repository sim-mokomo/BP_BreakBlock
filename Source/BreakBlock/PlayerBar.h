// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBar.generated.h"

UCLASS()
class BREAKBLOCK_API APlayerBar : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* barMesh;

public:
	// Sets default values for this pawn's properties
	APlayerBar();

	/* 軸入力に紐づけさせる命令です。移動に使用します */
	UFUNCTION()
	void MoveHorizontal(float AxisValue);

	/* 移動速度を表します */
	UPROPERTY(EditAnywhere)
		float moveSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};

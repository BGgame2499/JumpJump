// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "JumpCubeBase.generated.h"

UCLASS(config = Game)
class JUMPJUMP_API AJumpCubeBase : public AActor
{
	GENERATED_BODY()

public:
	AJumpCubeBase();

public:
	//创建Cube时要随机的最大和最小面积
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomArea")
		float RandomAreaMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomArea")
		float RandomAreaMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UStaticMeshComponent * Cube;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetZ", meta = (ExposeOnSpawn))	//创建对象时需要初始化的参数
		float TargetLocationZ;		//要到达的目标Z值

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isHitCube;

	bool isArrive;		//Cube是否到达目标位置

	int32 Score;		//当前Cube的分数
protected:
	virtual void BeginPlay() override;	//开始游戏后调用的函数

public:	
	virtual void Tick(float DeltaTime) override;	//每帧执行的事件驱动函数

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

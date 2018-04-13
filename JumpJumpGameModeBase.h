// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JumpJumpGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class JUMPJUMP_API AJumpJumpGameModeBase : public AGameModeBase		//游戏管理类
{
	GENERATED_BODY()
	
public:
	AJumpJumpGameModeBase();
public:
	//创建Cube时要随机的最大和最小距离
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomDistance")
		float RandomDistanceMax;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomDistance")
		float RandomDistanceMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThisScore")
		int32 Score;				//玩家当前总得分

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "jumpCube")//生成Cube类的类型
		TSubclassOf<class AJumpCubeBase> jumpCube;

	class AJumpCubeBase * thisJumpCube;	//当前Cube类的指针

	APawn*  playerPawn;			//玩家当前的指针
	FVector playerLocation;		//玩家当前的坐标

protected:
	virtual void BeginPlay() override;	//开始游戏后调用的函数

public:
	virtual void Tick(float DeltaTime) override;

	AJumpCubeBase * AddCube();	//创建添加Cube方法
};

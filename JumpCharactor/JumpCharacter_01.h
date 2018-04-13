// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JumpCharactor/JumpCharacterBase.h"
#include "JumpCharacter_01.generated.h"

/**
 * 
 */
UCLASS()
class JUMPJUMP_API AJumpCharacter_01 : public AJumpCharacterBase	//角色01号类
{
	GENERATED_BODY()
	
public:
	AJumpCharacter_01();

public:

	float narrowMinNum;			//模型最小缩小数值

	float narrowNum;			//每帧缩小的值

	float rotationMinNum;		//模型最小旋转数值

	float rotationNum;			//每帧旋转的值
protected:
	virtual void BeginPlay() override;	//开始游戏后调用的函数

public:
	virtual void Tick(float DeltaTime) override;	//每帧执行的事件驱动函数
	
	void SetMeshNarrow();	//设置模型的缩放
};

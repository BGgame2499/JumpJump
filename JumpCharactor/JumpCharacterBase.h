// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "JumpCharacterBase.generated.h"

UCLASS()
class JUMPJUMP_API AJumpCharacterBase : public ACharacter	//角色的基础类
{
	GENERATED_BODY()

public:
	AJumpCharacterBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "isDeath")
	bool isDeath;	//角色当前是否死亡的状态

	bool isJump;	//角色是否要跳跃

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "jumpPowerNum")	//将变量公开到引擎编辑器
	float jumpPowerNum;	//每帧要增加的跳跃力度

	float jumpPowerMax;	//角色跳跃的最大最小值

	float touchTime;	//用户触摸屏幕的时间

	

protected:
	virtual void BeginPlay() override;	//开始游戏后调用的函数

public:	
	virtual void Tick(float DeltaTime) override;	//每帧执行的事件驱动函数

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void BeginJump();	
	void EndJump();
	
};

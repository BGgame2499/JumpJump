// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpCharacter_01.h"
#include "Components/SkeletalMeshComponent.h"

AJumpCharacter_01::AJumpCharacter_01()	//初始化
{
	narrowMinNum = 0.4;
	narrowNum = 0.004;
	rotationMinNum = -30.0;
	rotationNum = -0.1;
}

void AJumpCharacter_01::BeginPlay()
{
	Super::BeginPlay();

}
void AJumpCharacter_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isJump && GetMesh()->RelativeScale3D.Z >= narrowMinNum && GetMesh()->RelativeRotation.Yaw >= rotationMinNum)	//判断是否准备跳跃并且判断缩放和旋转角是否到达阈值
	{
		SetMeshNarrow();
		GetMesh()->AddRelativeRotation(FRotator(rotationNum, 0, 0));		//调用缩放和旋转函数
	}
	else if (!isJump)
	{
		GetMesh()->SetRelativeScale3D(FVector(1,1,1));		//停止跳跃后将缩放和旋转恢复
		GetMesh()->SetRelativeRotation(FRotator(0, 0, 0));
	}

	if (GetActorLocation().Z <= 50)
	{
		isDeath = true;		//如果角色高度过低判定为死亡
	}
}

void AJumpCharacter_01::SetMeshNarrow()
{
	FVector vec(GetMesh()->RelativeScale3D.X + narrowNum, GetMesh()->RelativeScale3D.Y + narrowNum, GetMesh()->RelativeScale3D.Z - narrowNum);	
	GetMesh()->SetRelativeScale3D(vec);		//将设定好的缩放量设置

}



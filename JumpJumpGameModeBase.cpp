// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpJumpGameModeBase.h"
#include "JumpCube/JumpCubeBase.h"
#include"Engine.h"
AJumpJumpGameModeBase::AJumpJumpGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	RandomDistanceMax = 700;	//初始化要随机的方块大小
	RandomDistanceMin = 200;

}

void AJumpJumpGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
		playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();	//获取角色指针
		playerLocation = playerPawn->GetActorLocation();		//获取角色当前的坐标
}
void AJumpJumpGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (thisJumpCube == NULL || thisJumpCube->isHitCube == true)
	{
		if (thisJumpCube != NULL)	//如果当前的Cube对象不为空获取Cube内存储的得分
		{Score += thisJumpCube->Score;}
		
		thisJumpCube = 	AddCube();	//将创建的Cube指针存储
		
	}

}

AJumpCubeBase * AJumpJumpGameModeBase::AddCube()
{
	if (jumpCube != NULL)	//检查要创建的类型是否为空
	{
		playerLocation = playerPawn->GetActorLocation();
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		playerLocation.X += FMath::RandRange(RandomDistanceMin, RandomDistanceMax);		//将pawn当前的X加上随机一个值得出下一个Cube的X位置
		playerLocation.Z += 400;	//让Cube出现在比玩家高的地方
		return GetWorld()->SpawnActor<AJumpCubeBase>(jumpCube, playerLocation, FRotator(0, 0, 0), ActorSpawnParams);	//返回生成的Cube指针
	}
	return NULL;
}



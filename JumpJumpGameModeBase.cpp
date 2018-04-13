// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpJumpGameModeBase.h"
#include "JumpCube/JumpCubeBase.h"
#include"Engine.h"
AJumpJumpGameModeBase::AJumpJumpGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	RandomDistanceMax = 700;	//��ʼ��Ҫ����ķ����С
	RandomDistanceMin = 200;

}

void AJumpJumpGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
		playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();	//��ȡ��ɫָ��
		playerLocation = playerPawn->GetActorLocation();		//��ȡ��ɫ��ǰ������
}
void AJumpJumpGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (thisJumpCube == NULL || thisJumpCube->isHitCube == true)
	{
		if (thisJumpCube != NULL)	//�����ǰ��Cube����Ϊ�ջ�ȡCube�ڴ洢�ĵ÷�
		{Score += thisJumpCube->Score;}
		
		thisJumpCube = 	AddCube();	//��������Cubeָ��洢
		
	}

}

AJumpCubeBase * AJumpJumpGameModeBase::AddCube()
{
	if (jumpCube != NULL)	//���Ҫ�����������Ƿ�Ϊ��
	{
		playerLocation = playerPawn->GetActorLocation();
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		playerLocation.X += FMath::RandRange(RandomDistanceMin, RandomDistanceMax);		//��pawn��ǰ��X�������һ��ֵ�ó���һ��Cube��Xλ��
		playerLocation.Z += 400;	//��Cube�����ڱ���Ҹߵĵط�
		return GetWorld()->SpawnActor<AJumpCubeBase>(jumpCube, playerLocation, FRotator(0, 0, 0), ActorSpawnParams);	//�������ɵ�Cubeָ��
	}
	return NULL;
}



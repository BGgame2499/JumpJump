// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JumpJumpGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class JUMPJUMP_API AJumpJumpGameModeBase : public AGameModeBase		//��Ϸ������
{
	GENERATED_BODY()
	
public:
	AJumpJumpGameModeBase();
public:
	//����CubeʱҪ�����������С����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomDistance")
		float RandomDistanceMax;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomDistance")
		float RandomDistanceMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ThisScore")
		int32 Score;				//��ҵ�ǰ�ܵ÷�

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "jumpCube")//����Cube�������
		TSubclassOf<class AJumpCubeBase> jumpCube;

	class AJumpCubeBase * thisJumpCube;	//��ǰCube���ָ��

	APawn*  playerPawn;			//��ҵ�ǰ��ָ��
	FVector playerLocation;		//��ҵ�ǰ������

protected:
	virtual void BeginPlay() override;	//��ʼ��Ϸ����õĺ���

public:
	virtual void Tick(float DeltaTime) override;

	AJumpCubeBase * AddCube();	//�������Cube����
};

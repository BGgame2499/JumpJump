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
	//����CubeʱҪ�����������С���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomArea")
		float RandomAreaMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnRandomArea")
		float RandomAreaMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UStaticMeshComponent * Cube;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetZ", meta = (ExposeOnSpawn))	//��������ʱ��Ҫ��ʼ���Ĳ���
		float TargetLocationZ;		//Ҫ�����Ŀ��Zֵ

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isHitCube;

	bool isArrive;		//Cube�Ƿ񵽴�Ŀ��λ��

	int32 Score;		//��ǰCube�ķ���
protected:
	virtual void BeginPlay() override;	//��ʼ��Ϸ����õĺ���

public:	
	virtual void Tick(float DeltaTime) override;	//ÿִ֡�е��¼���������

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

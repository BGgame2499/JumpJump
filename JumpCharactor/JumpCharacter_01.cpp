// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpCharacter_01.h"
#include "Components/SkeletalMeshComponent.h"

AJumpCharacter_01::AJumpCharacter_01()	//��ʼ��
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

	if (isJump && GetMesh()->RelativeScale3D.Z >= narrowMinNum && GetMesh()->RelativeRotation.Yaw >= rotationMinNum)	//�ж��Ƿ�׼����Ծ�����ж����ź���ת���Ƿ񵽴���ֵ
	{
		SetMeshNarrow();
		GetMesh()->AddRelativeRotation(FRotator(rotationNum, 0, 0));		//�������ź���ת����
	}
	else if (!isJump)
	{
		GetMesh()->SetRelativeScale3D(FVector(1,1,1));		//ֹͣ��Ծ�����ź���ת�ָ�
		GetMesh()->SetRelativeRotation(FRotator(0, 0, 0));
	}

	if (GetActorLocation().Z <= 50)
	{
		isDeath = true;		//�����ɫ�߶ȹ����ж�Ϊ����
	}
}

void AJumpCharacter_01::SetMeshNarrow()
{
	FVector vec(GetMesh()->RelativeScale3D.X + narrowNum, GetMesh()->RelativeScale3D.Y + narrowNum, GetMesh()->RelativeScale3D.Z - narrowNum);	
	GetMesh()->SetRelativeScale3D(vec);		//���趨�õ�����������

}



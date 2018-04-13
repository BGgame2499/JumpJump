// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpCharacterBase.h"
#include"GameFramework/CharacterMovementComponent.h"


AJumpCharacterBase::AJumpCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	isDeath = false;
	jumpPowerMax = 3000000.0;	//��ʼ����Ծ����
	jumpPowerNum = 10000.0;
}

void AJumpCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AJumpCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (isJump)		//�Ƿ����׼����Ծ
	{
		if (touchTime < jumpPowerMax)	//����ʱ��С��������Ծ��������Ⱦ���������
		{

			touchTime += jumpPowerNum;
		}
	}
}

void AJumpCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)	//�����󶨺���
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this,&AJumpCharacterBase::BeginJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AJumpCharacterBase::EndJump);

}

void AJumpCharacterBase::BeginJump()
{
	if (!isDeath)
	{
		touchTime = 0.f;	//���°������Ƚ�ʱ������
		isJump = true;		//����Ծ״̬����Ϊ��

	}
}

void AJumpCharacterBase::EndJump()
{
	isJump = false;

	Jump();//������Ծ����

	GetCharacterMovement()->MaxAcceleration = touchTime;	//���õ�ǰ���ٶȵ�ֵ
	AddMovementInput(GetActorForwardVector(), touchTime);	//ʩ����ǰ����

}


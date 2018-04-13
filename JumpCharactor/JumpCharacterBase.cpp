// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpCharacterBase.h"
#include"GameFramework/CharacterMovementComponent.h"


AJumpCharacterBase::AJumpCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	isDeath = false;
	jumpPowerMax = 3000000.0;	//初始化跳跃力度
	jumpPowerNum = 10000.0;
}

void AJumpCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AJumpCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (isJump)		//是否可以准备跳跃
	{
		if (touchTime < jumpPowerMax)	//触摸时间小于允许跳跃的最大力度就增加力度
		{

			touchTime += jumpPowerNum;
		}
	}
}

void AJumpCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)	//按键绑定函数
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this,&AJumpCharacterBase::BeginJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AJumpCharacterBase::EndJump);

}

void AJumpCharacterBase::BeginJump()
{
	if (!isDeath)
	{
		touchTime = 0.f;	//按下按键后先将时间清零
		isJump = true;		//将跳跃状态设置为真

	}
}

void AJumpCharacterBase::EndJump()
{
	isJump = false;

	Jump();//调用跳跃函数

	GetCharacterMovement()->MaxAcceleration = touchTime;	//设置当前加速度的值
	AddMovementInput(GetActorForwardVector(), touchTime);	//施加向前的力

}


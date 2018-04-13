// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "JumpCharacterBase.generated.h"

UCLASS()
class JUMPJUMP_API AJumpCharacterBase : public ACharacter	//��ɫ�Ļ�����
{
	GENERATED_BODY()

public:
	AJumpCharacterBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "isDeath")
	bool isDeath;	//��ɫ��ǰ�Ƿ�������״̬

	bool isJump;	//��ɫ�Ƿ�Ҫ��Ծ

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "jumpPowerNum")	//����������������༭��
	float jumpPowerNum;	//ÿ֡Ҫ���ӵ���Ծ����

	float jumpPowerMax;	//��ɫ��Ծ�������Сֵ

	float touchTime;	//�û�������Ļ��ʱ��

	

protected:
	virtual void BeginPlay() override;	//��ʼ��Ϸ����õĺ���

public:	
	virtual void Tick(float DeltaTime) override;	//ÿִ֡�е��¼���������

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void BeginJump();	
	void EndJump();
	
};

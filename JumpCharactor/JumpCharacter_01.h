// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JumpCharactor/JumpCharacterBase.h"
#include "JumpCharacter_01.generated.h"

/**
 * 
 */
UCLASS()
class JUMPJUMP_API AJumpCharacter_01 : public AJumpCharacterBase	//��ɫ01����
{
	GENERATED_BODY()
	
public:
	AJumpCharacter_01();

public:

	float narrowMinNum;			//ģ����С��С��ֵ

	float narrowNum;			//ÿ֡��С��ֵ

	float rotationMinNum;		//ģ����С��ת��ֵ

	float rotationNum;			//ÿ֡��ת��ֵ
protected:
	virtual void BeginPlay() override;	//��ʼ��Ϸ����õĺ���

public:
	virtual void Tick(float DeltaTime) override;	//ÿִ֡�е��¼���������
	
	void SetMeshNarrow();	//����ģ�͵�����
};

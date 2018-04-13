
#include "JumpCubeBase.h"
#include "Engine.h"

AJumpCubeBase::AJumpCubeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	isHitCube = false;
	isArrive = false;
	RandomAreaMax = 2.0f;
	RandomAreaMin = 0.5f;

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));	//��ʼ��cubeģ��
	Cube->OnComponentBeginOverlap.AddDynamic(this, &AJumpCubeBase::OnOverlapBegin);		//ΪCube����ײ�¼�

}

void AJumpCubeBase::BeginPlay()
{
	Super::BeginPlay();

	Cube->SetRelativeScale3D(FVector(FMath::RandRange(RandomAreaMin, RandomAreaMax), FMath::RandRange(RandomAreaMin, RandomAreaMax), 1));	//����������
	TargetLocationZ = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z - 80;
	{
		float CM = this->GetActorLocation().X - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X;
		if (CM < 300)	//���ݳ��������ж�Cube����
		{
			Score = 1;
		}
		else if (CM < 550)
		{
			Score = 2;
		}
		else if (CM < 700)
		{
			Score = 3;
		}
	}
}

void AJumpCubeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{	//��Cube�½��������ǰ
		if (isArrive == false && this->GetActorLocation().Z >= TargetLocationZ)
		{
			AddActorLocalOffset(FVector(0, 0, -5));
		}
		else  //����Ѿ����������ǰ��ֹͣ�½�
		{
			isArrive = true;
		}
	}

	if (this->GetActorLocation().X <= GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X - 500)
	{
		this->Destroy();	//�����ɫ������ǰCube500cm��ɾ������
	}


}

void AJumpCubeBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	isHitCube = true;		//�����ɫ�����˷��齫��ײ״̬��Ϊ��
}

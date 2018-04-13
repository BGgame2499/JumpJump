
#include "JumpCubeBase.h"
#include "Engine.h"

AJumpCubeBase::AJumpCubeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	isHitCube = false;
	isArrive = false;
	RandomAreaMax = 2.0f;
	RandomAreaMin = 0.5f;

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));	//初始化cube模型
	Cube->OnComponentBeginOverlap.AddDynamic(this, &AJumpCubeBase::OnOverlapBegin);		//为Cube绑定碰撞事件

}

void AJumpCubeBase::BeginPlay()
{
	Super::BeginPlay();

	Cube->SetRelativeScale3D(FVector(FMath::RandRange(RandomAreaMin, RandomAreaMax), FMath::RandRange(RandomAreaMin, RandomAreaMax), 1));	//设置随机面积
	TargetLocationZ = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z - 80;
	{
		float CM = this->GetActorLocation().X - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X;
		if (CM < 300)	//根据出生距离判断Cube分数
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
	{	//将Cube下降到玩家面前
		if (isArrive == false && this->GetActorLocation().Z >= TargetLocationZ)
		{
			AddActorLocalOffset(FVector(0, 0, -5));
		}
		else  //如果已经到达玩家面前则停止下降
		{
			isArrive = true;
		}
	}

	if (this->GetActorLocation().X <= GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X - 500)
	{
		this->Destroy();	//如果角色超过当前Cube500cm则删除自身
	}


}

void AJumpCubeBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	isHitCube = true;		//如果角色碰到了方块将碰撞状态改为真
}

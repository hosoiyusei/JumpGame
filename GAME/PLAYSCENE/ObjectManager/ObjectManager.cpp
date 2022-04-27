#include"ObjectManager.h"
#include"../SaveData/SaveData.h"

#include"../Player/Player.h"
#include"Object/Object_0.h"

ObjectManager::ObjectManager()
	:mpObject()
	,itr()
	,mpPlayer(nullptr)
	, mStageNum(0)
	,mpSaveData(nullptr)
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::Initialize(Player* pPlayer, SaveData* pSaveData)
{
	mpPlayer = pPlayer;
	mpSaveData = pSaveData;

	mStageNum = mpSaveData->Road(3);

	StageChange(mStageNum);
}

void ObjectManager::Update()
{
	for (itr = mpObject.begin(); itr != mpObject.end(); itr++)
	{
		if ((*itr) != nullptr)
			(*itr)->Update();
	}

	CheckHit();

	mpSaveData->Save(mpPlayer->GetPos().mX, mpPlayer->GetPos().mY, mStageNum);
}

void ObjectManager::Draw()
{
	for (itr = mpObject.begin(); itr != mpObject.end(); itr++)
	{
		if ((*itr) != nullptr)
			(*itr)->Draw();
	}
	if (mStageNum == 6)
		DrawFormatString(290, 100, GetColor(0, 255, 0), "GameClear");
}

void ObjectManager::Finalize()
{
	int i = mpObject.size();
	for (int I = 0; I < i; I++)
	{
		for (itr = mpObject.begin(); itr != mpObject.end(); itr++)
		{
			if ((*itr) == nullptr)
				continue;
			(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			mpObject.erase(itr);
			break;
		}
	}
}

void ObjectManager::CheckHit()
{
	for (itr = mpObject.begin(); itr != mpObject.end(); itr++)
	{
		if ((*itr) == nullptr || mpPlayer == nullptr)
			continue;
		//ボールとパドルの当たり判定
		unsigned int ret = mpPlayer->CheckHit().CheckHit((*itr)->CheckHit());

		if (ret == AABB_LEFT)// 左に当たっていた
		{
			mpPlayer->SetPosX((*itr)->GetPos().mX - (*itr)->SizeX() - 20);
			break;
		}
		else if (ret == AABB_RIGHT)// 右に当たっていた
		{
			mpPlayer->SetPosX((*itr)->GetPos().mX + (*itr)->SizeX() + 20);
			break;
		}
		else if (ret == AABB_UP)// 上に当たっていた
		{
			mpPlayer->Ground();
			mpPlayer->SetPosY((*itr)->GetPos().mY - (*itr)->SizeY() - 20);
			break;
		}
		else if (ret == AABB_DOWN)// 下に当たっていた
		{
			mpPlayer->HitTop();
			mpPlayer->SetPosY((*itr)->GetPos().mY + (*itr)->SizeY() + 20);
			break;
		}
	}
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

void ObjectManager::CreateStage_1()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(320.0f, 480.0f, 500, 50);
	(--itr);
	(*itr)->Initialize(320.0f, 300.0f, 50, 20);
	(--itr);
	(*itr)->Initialize(450.0f, 200.0f, 50, 20);
	(--itr);
	(*itr)->Initialize(150.0f, 0.0f, 250, 50);
	(--itr);
	(*itr)->Initialize(640.0f, 0.0f, 50, 50);
}

void ObjectManager::CreateStage_2()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(150.0f, 480.0f, 250, 50);
	(--itr);
	(*itr)->Initialize(640.0f, 480.0f, 50, 50);
	(--itr);
	(*itr)->Initialize(150.0f, 300.0f, 200, 30);
	(--itr);
	(*itr)->Initialize(500.0f, 150.0f, 200, 30);
	(--itr);
	(*itr)->Initialize(600.0f, 0.0f, 100, 50);
	(--itr);
	(*itr)->Initialize(150.0f, 0.0f, 200, 50);
}

void ObjectManager::CreateStage_3()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(600.0f, 480.0f, 100, 50);
	(--itr);
	(*itr)->Initialize(150.0f, 480.0f, 200, 50);
	(--itr);
	(*itr)->Initialize(0.0f, 240.0f, 50, 190);
	(--itr);
	(*itr)->Initialize(640.0f, 240.0f, 50, 190);
	(--itr);
	(*itr)->Initialize(540.0f, 250.0f, 50, 25);
	(--itr);
	(*itr)->Initialize(200.0f, 150.0f, 150, 25);
	(--itr);
	(*itr)->Initialize(0.0f, 0.0f, 100, 50);
	(--itr);
	(*itr)->Initialize(500.0f, 0.0f, 300, 50);
}

void ObjectManager::CreateStage_4()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(0.0f, 480.0f, 100, 50);
	(--itr);
	(*itr)->Initialize(500.0f, 480.0f, 300, 50);
	(--itr);
	(*itr)->Initialize(-50.0f, 240.0f, 50, 190);
	(--itr);
	(*itr)->Initialize(690.0f, 240.0f, 50, 190);
	(--itr);
	(*itr)->Initialize(220.0f, 200.0f, 220, 30);
	(--itr);
	(*itr)->Initialize(590.0f, 200.0f, 50, 30);
	(--itr);
	(*itr)->Initialize(220.0f, 0.0f, 300, 50);
	(--itr);
	(*itr)->Initialize(660.0f, 0.0f, 50, 50);
}

void ObjectManager::CreateStage_5()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(220.0f, 480.0f, 300, 50);
	(--itr);
	(*itr)->Initialize(660.0f, 480.0f, 50, 50);
	(--itr);
	(*itr)->Initialize(-50.0f, 190.0f, 50, 240);
	(--itr);
	(*itr)->Initialize(690.0f, 190.0f, 50, 240);
	(--itr);
	(*itr)->Initialize(490.0f, 250.0f, 150, 25);
	(--itr);
	(*itr)->Initialize(365.0f, 390.0f, 25, 40);
	(--itr);
	(*itr)->Initialize(170.0f, 150.0f, 200, 25);
}

void ObjectManager::CreateStage_6()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(0.0f, 0.0f, 280, 50);
	(--itr);
	(*itr)->Initialize(640.0f, 0.0f, 280, 50);
	(--itr);
	(*itr)->Initialize(255.0f, 90.0f, 25, 40);
	(--itr);
	(*itr)->Initialize(385.0f, 90.0f, 25, 40);
	(--itr);
	(*itr)->Initialize(200.0f, 340.0f, 60, 20);
	(--itr);
	(*itr)->Initialize(500.0f, 300.0f, 60, 20);
	(--itr);
	(*itr)->Initialize(320.0f, 260.0f, 30, 20);
}

void ObjectManager::CreateStage_7()
{
	mpObject.push_back(new Object_0());
	mpObject.push_back(new Object_0());
	itr = mpObject.end();
	(--itr);
	(*itr)->Initialize(320.0f, -50.0f, 400, 50);
	(--itr);
	(*itr)->Initialize(320.0f, 480.0f, 400, 50);
}

void ObjectManager::DeleteStage()
{
	int i = mpObject.size();
	for (int I = 0; I < i; I++)
	{
		for (itr = mpObject.begin(); itr != mpObject.end(); itr++)
		{
			if ((*itr) == nullptr)
				continue;
			(*itr)->Finalize();
			delete (*itr);
			(*itr) = nullptr;
			mpObject.erase(itr);
			break;
		}
	}
}

void ObjectManager::StageChange(int i)
{
	if (i == 0)
	{
		DeleteStage();
		CreateStage_1();
	}
	else if (i == 1)
	{
		DeleteStage();
		CreateStage_2();
	}
	else if (i == 2)
	{
		DeleteStage();
		CreateStage_3();
	}
	else if (i == 3)
	{
		DeleteStage();
		CreateStage_4();
	}
	else if (i == 4)
	{
		DeleteStage();
		CreateStage_5();
	}
	else if (i == 5)
	{
		DeleteStage();
		CreateStage_6();
	}
	else if (i == 6)
	{
		DeleteStage();
		CreateStage_7();
	}
}
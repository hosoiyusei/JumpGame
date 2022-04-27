#pragma once
#include <list>

class Object;
class Player;
class SaveData;

class ObjectManager
{
private:

	int mStageNum;

	std::list<Object*> mpObject;
	std::list<Object*>::iterator itr;

	Player* mpPlayer;

	SaveData* mpSaveData;

public:

	ObjectManager();
	~ObjectManager();

	void Initialize(Player* pPlayer, SaveData* pSaveData);

	void Update();

	void Draw();

	void Finalize();

	void StageUp()
	{
		mStageNum++;
		StageChange(mStageNum);
	}

	void StageDown()
	{
		mStageNum--;
		StageChange(mStageNum);
	}

private:

	void CheckHit();

	void CreateStage_1();

	void CreateStage_2();

	void CreateStage_3();

	void CreateStage_4();

	void CreateStage_5();

	void CreateStage_6();

	void CreateStage_7();

	void DeleteStage();

	void StageChange(int i);
};
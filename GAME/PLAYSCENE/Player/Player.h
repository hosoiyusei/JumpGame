#pragma once
#include"../../Utility.h"
#include"../BoxCollider/BoxCollider.h"

class ObjectManager;
class SaveData;

class Player
{
private:

	Float2 mPos;
	Float2 mfirstPos, mSecondPos;
	
	// ìñÇΩÇËîªíËç\ë¢ëÃ
	BoxCollider mCollider;

	const float mSize;

	float mGravity;

	int mMouseX, mMouseY;

	float mVelY;

	bool mfirstSetFlag, mSecondSetFlag, mJump;

	int mClickTimer, mClickTimer2, mClickTimer3, mClickTimer4;

	const float mSpeed;

	float mAngle;

	bool mActive;

	float mX, mY, mX2, mY2, mVX, mVY;

	bool mFall;

	float test=0,test2=0,test3=0;

	ObjectManager* mpObjectManager;

	SaveData* mpSaveData;

public:

	Player();
	~Player();

	void Initialize(ObjectManager* pObjectManager, SaveData* pSaveData);

	void Update();

	void Draw();

	void Finalize();

	BoxCollider CheckHit()
	{
		return mCollider;
	}

	Float2 GetPos()
	{
		return mPos;
	}

	void Ground();

	void HitTop();

	void SetPosX(float x);

	void SetPosY(float y);

private:

	void Move();

	void Search();

	void Fall();
};
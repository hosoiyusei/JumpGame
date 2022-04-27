#include"Player.h"
#include"../../GameMain.h"
#include<math.h>
#include"../ObjectManager/ObjectManager.h"
#include"../SaveData/SaveData.h"

Player::Player()
	:mPos()
	, mfirstPos()
	, mSecondPos()
	, mCollider()
	, mSize(20.0f)
	, mGravity(0.5f)
	, mVelY(0.0f)
	, mActive(true)
	, mMouseX(0)
	, mMouseY(0)
	, mfirstSetFlag(false)
	, mSecondSetFlag(false)
	, mClickTimer(0)
	, mClickTimer2(0)
	, mClickTimer3(0)
	, mClickTimer4(0)
	, mSpeed(3.0f)
	, mX(0.0f)
	, mY(0.0f)
	, mVX(0.0f)
	, mVY(0.0f)
	, mJump(false)
	, mAngle(0.0f)
	,mX2(0.0f)
	,mY2(0.0f)
	, mFall(false)
	,mpObjectManager(nullptr)
	,mpSaveData(nullptr)
{

}

Player::~Player()
{

}

void Player::Initialize(ObjectManager* pObjectManager, SaveData* pSaveData)
{
	mpObjectManager = pObjectManager;
	mpSaveData = pSaveData;

	mPos.mX = mpSaveData->Road(1);
	mPos.mY = mpSaveData->Road(2);

	test = mpSaveData->Road(1);
	test2 = mpSaveData->Road(2);
	test3 = mpSaveData->Road(3);

	// 当たり判定構造体に四隅の座標を代入
	mCollider.mX1 = mPos.mX - mSize;
	mCollider.mY1 = mPos.mY - mSize;
	mCollider.mX2 = mPos.mX + mSize;
	mCollider.mY2 = mPos.mY + mSize;
}

void Player::Update()
{
	Move();

	//重力処理
	mVelY += mGravity;

	mPos.mY += mVelY;

	Fall();

	// 当たり判定構造体に四隅の座標を代入
	mCollider.mX1 = mPos.mX - mSize;
	mCollider.mY1 = mPos.mY - mSize;
	mCollider.mX2 = mPos.mX + mSize;
	mCollider.mY2 = mPos.mY + mSize;
}

void Player::Draw()
{
	DrawBox(
		mPos.mX - mSize,
		mPos.mY - mSize,
		mPos.mX + mSize,
		mPos.mY + mSize,
		GetColor(255, 255, 255), FALSE);

	DrawCircle(mMouseX, mMouseY, 5, GetColor(255, 0, 0), TRUE);
	if (mfirstSetFlag == true&& mSecondSetFlag==false)
	{
		DrawTriangle(
			mfirstPos.mX, mfirstPos.mY,
			mfirstPos.mX + mX, mfirstPos.mY + mY,
			mfirstPos.mX + mX2, mfirstPos.mY + mY2,
			GetColor(255, 255, 255), TRUE
		);
		DrawLine(mfirstPos.mX, mfirstPos.mY, mSecondPos.mX, mSecondPos.mY, GetColor(255, 255, 255), TRUE);
		DrawLine(mfirstPos.mX, mfirstPos.mY, mSecondPos.mX, mSecondPos.mY, GetColor(255, 255, 255), TRUE);
		DrawCircle(mfirstPos.mX, mfirstPos.mY, 5, GetColor(0, 255, 0), TRUE);
		DrawCircle(mSecondPos.mX, mSecondPos.mY, 5, GetColor(0, 0, 255), TRUE);
	}

	//DrawFormatString(100, 100, GetColor(255, 255, 255), "%f", test);
	//DrawFormatString(100, 120, GetColor(255, 255, 255), "%f", test2);
	//DrawFormatString(100, 140, GetColor(255, 255, 255), "%f", test3);
}

void Player::Finalize()
{
	mpSaveData->Save(0, 0, 0);
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

void Player::Move()
{
	if (mPos.mX-mSize > SCREEN_RIGHT)
	{
		mPos.mX = 0-mSize;
	}
	if (mPos.mX+mSize < 0)
	{
		mPos.mX = SCREEN_RIGHT+mSize;
	}

	GetMousePoint(&mMouseX, &mMouseY);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0&& mJump==false)
	{
		if (mClickTimer < 2)
			mClickTimer++;
		if (mClickTimer == 1)
		{
			mfirstPos.mX = mMouseX;
			mfirstPos.mY = mMouseY;
			mfirstSetFlag = true;
		}
	}
	if (mfirstSetFlag == true && mSecondSetFlag == false)
	{
		mSecondPos.mX = mMouseX;
		mSecondPos.mY = mMouseY;
	}

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0 && mfirstSetFlag == true)
	{
		if (mClickTimer2<2)
			mClickTimer2++;
		if (mClickTimer2 == 1)
		{
			mSecondPos.mX = mMouseX;
			mSecondPos.mY = mMouseY;
			mSecondSetFlag = true;
		}
	}

	if (mfirstSetFlag == true && mSecondSetFlag == true)
	{
		mJump = true;
		mFall = true;
		if (mClickTimer3 < 2)
			mClickTimer3++;

		mVX = mfirstPos.mX - mSecondPos.mX;
		mVY = mfirstPos.mY - mSecondPos.mY;

		if (mClickTimer3 == 1)
		{
			mVelY = mVY / 15.0f;
			mClickTimer = 0;
			mClickTimer2 = 0;
			mClickTimer3 = 0;
			mfirstSetFlag = false;
			mSecondSetFlag = false;
		}
	}
	mPos.mX += mVX / 30.0f;

	if (mPos.mY < 0)
	{
		mpObjectManager->StageUp();
		mPos.mY = 480;
	}
		
	if (mPos.mY > 480)
	{
		mpObjectManager->StageDown();
		mPos.mY = 0;
	}
		

	Search();
}

void Player::Search()
{
	mAngle = atan2f(mfirstPos.mY -mMouseY, mfirstPos.mX - mMouseX);

	mX = -30 * cos(mAngle - 0.5f);
	mY = -30 * sin(mAngle - 0.5f);
	mX2 = -30 * cos(mAngle + 0.5f);
	mY2 = -30 * sin(mAngle + 0.5f);
}

void Player::Fall()
{
	if (mFall == true)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (mClickTimer4 < 2)
				mClickTimer4++;
			if (mClickTimer4 == 1)
			{
				mVelY = 30.0f;
				mVX = 0.0f;
			}
		}
	}
}

void Player::Ground()
{
	mVelY = 0;
	mVX = 0.0f;
	mVY = 0.0f;
	mJump = false;
	mFall = false;
	mClickTimer4 = 0;
}

void Player::HitTop()
{
	mVelY = 0;
}

void Player::SetPosX(float x)
{
	mPos.mX = x;
	mVX *= -1.0f;
}

void Player::SetPosY(float y)
{
	mPos.mY = y;
}
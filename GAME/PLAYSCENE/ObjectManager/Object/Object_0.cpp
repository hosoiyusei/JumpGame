#include"Object_0.h"

Object_0::Object_0()
	:mPos()
	,mSizeX(0.0f)
	,mSizeY(0.0f)
	,mCollider()
{

}

Object_0::~Object_0()
{

}

void Object_0::Initialize(float x, float y, float sizex, float sizey)
{
	mPos.mX = x;
	mPos.mY = y;
	mSizeX = sizex;
	mSizeY = sizey;

	// 当たり判定構造体に四隅の座標を代入
	mCollider.mX1 = mPos.mX - mSizeX;
	mCollider.mY1 = mPos.mY - mSizeY;
	mCollider.mX2 = mPos.mX + mSizeX;
	mCollider.mY2 = mPos.mY + mSizeY;
}

void Object_0::Update()
{
	// 当たり判定構造体に四隅の座標を代入
	mCollider.mX1 = mPos.mX - mSizeX;
	mCollider.mY1 = mPos.mY - mSizeY;
	mCollider.mX2 = mPos.mX + mSizeX;
	mCollider.mY2 = mPos.mY + mSizeY;
}

void Object_0::Draw()
{
	DrawBox(
		mPos.mX - mSizeX,
		mPos.mY - mSizeY,
		mPos.mX + mSizeX,
		mPos.mY + mSizeY,
		GetColor(255, 0, 255), FALSE
	);
}

void Object_0::Finalize()
{

}
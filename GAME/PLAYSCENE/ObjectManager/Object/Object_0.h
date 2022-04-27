#pragma once
#include"Object.h"

class Object_0:public Object
{
private:

	Float2 mPos;

	// ìñÇΩÇËîªíËç\ë¢ëÃ
	BoxCollider mCollider;

	float mSizeX, mSizeY;

public:

	Object_0();
	~Object_0();

	void Initialize(float x, float y, float sizex,float sizey) override;

	void Update() override;

	void Draw() override;

	void Finalize() override;

	Float2 GetPos() override
	{
		return mPos;
	}

	BoxCollider CheckHit() override
	{
		return mCollider;
	}

	float SizeX() override
	{
		return mSizeX;
	}

	float SizeY() override
	{
		return mSizeY;
	}
};
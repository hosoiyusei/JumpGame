#pragma once

// 当たった際の位置比率
#define AABB_NONE			(0)
#define AABB_LEFT			(1<<0)
#define AABB_RIGHT			(1<<1)
#define AABB_UP				(1<<2)
#define AABB_DOWN			(1<<3)

struct BoxCollider
{
	// 四角の左上と右下
	float mX1;
	float mY1;
	float mX2;
	float mY2;

	BoxCollider()
		:mX1(0.0f)
		,mY1(0.0f)
		,mX2(0.0f)
		,mY2(0.0f)
	{

	}

	// 当たり判定（AABB）
	unsigned int CheckHit(BoxCollider col);
};
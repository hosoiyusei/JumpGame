#pragma once

// ���������ۂ̈ʒu�䗦
#define AABB_NONE			(0)
#define AABB_LEFT			(1<<0)
#define AABB_RIGHT			(1<<1)
#define AABB_UP				(1<<2)
#define AABB_DOWN			(1<<3)

struct BoxCollider
{
	// �l�p�̍���ƉE��
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

	// �����蔻��iAABB�j
	unsigned int CheckHit(BoxCollider col);
};
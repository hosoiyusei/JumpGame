#include "BoxCollider.h"

unsigned int BoxCollider::CheckHit(BoxCollider col)
{
	// �߂�l
	unsigned int ret = AABB_NONE;

	// �����蔻������
	if (!(mX1 < col.mX2 && mY1 < col.mY2 && mX2 > col.mX1 && mY2 > col.mY1))
	{
		// �������Ă�������Ώ������Ȃ�
		return ret;
	}

	// �֐����̊m�F�p�t���O
	unsigned int checkFlag = AABB_NONE;

	// �߂荞�݋�̊m�F�p�ϐ�
	float checkXRatio = 0.0f;
	float checkYRatio = 0.0f;

	// ���g�̕��ƍ������v�Z
	float width = mX2 - mX1;
	float height = mY2 - mY1;

	// �e�����̂߂荞�݋
	float leftRatio = (mX2 - col.mX1) / width;
	float rightRatio = (col.mX2 - mX1) / width;
	float upRatio = (mY2 - col.mY1) / height;
	float downRatio = (col.mY2 - mY1) / height;

	//	���E�̔䗦���珬���������`�F�b�N�ɓ����
	if (leftRatio < rightRatio)
	{
		// ���Ɋ���Ă���
		checkFlag |= AABB_LEFT;
		checkXRatio = leftRatio;
	}
	else
	{
		// �E�Ɋ���Ă���
		checkFlag |= AABB_RIGHT;
		checkXRatio = rightRatio;
	}

	//	�㉺�̔䗦���珬���������`�F�b�N�ɓ����
	if (upRatio < downRatio)
	{
		// ��Ɋ���Ă���
		checkFlag |= AABB_UP;
		checkYRatio = upRatio;
	}
	else
	{
		// ���Ɋ���Ă���
		checkFlag |= AABB_DOWN;
		checkYRatio = downRatio;
	}

	//	�㉺�ƍ��E�Ŕ䗦�̏���������߂�l�ɓ����
	if (checkXRatio < checkYRatio)
	{
		// ���E�̃t���O���c��
		ret = checkFlag & (AABB_LEFT | AABB_RIGHT);
	}
	else if (checkXRatio > checkYRatio)
	{
		// �㉺�̃t���O���c��
		ret = checkFlag & (AABB_UP | AABB_DOWN);
	}

	return ret;
}

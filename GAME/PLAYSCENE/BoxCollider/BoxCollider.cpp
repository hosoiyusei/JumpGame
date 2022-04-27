#include "BoxCollider.h"

unsigned int BoxCollider::CheckHit(BoxCollider col)
{
	// 戻り値
	unsigned int ret = AABB_NONE;

	// 当たり判定を取る
	if (!(mX1 < col.mX2 && mY1 < col.mY2 && mX2 > col.mX1 && mY2 > col.mY1))
	{
		// 当たってい無ければ処理しない
		return ret;
	}

	// 関数内の確認用フラグ
	unsigned int checkFlag = AABB_NONE;

	// めり込み具合の確認用変数
	float checkXRatio = 0.0f;
	float checkYRatio = 0.0f;

	// 自身の幅と高さを計算
	float width = mX2 - mX1;
	float height = mY2 - mY1;

	// 各方向のめり込み具合
	float leftRatio = (mX2 - col.mX1) / width;
	float rightRatio = (col.mX2 - mX1) / width;
	float upRatio = (mY2 - col.mY1) / height;
	float downRatio = (col.mY2 - mY1) / height;

	//	左右の比率から小さい方をチェックに入れる
	if (leftRatio < rightRatio)
	{
		// 左に寄っている
		checkFlag |= AABB_LEFT;
		checkXRatio = leftRatio;
	}
	else
	{
		// 右に寄っている
		checkFlag |= AABB_RIGHT;
		checkXRatio = rightRatio;
	}

	//	上下の比率から小さい方をチェックに入れる
	if (upRatio < downRatio)
	{
		// 上に寄っている
		checkFlag |= AABB_UP;
		checkYRatio = upRatio;
	}
	else
	{
		// 下に寄っている
		checkFlag |= AABB_DOWN;
		checkYRatio = downRatio;
	}

	//	上下と左右で比率の小さい方を戻り値に入れる
	if (checkXRatio < checkYRatio)
	{
		// 左右のフラグを残す
		ret = checkFlag & (AABB_LEFT | AABB_RIGHT);
	}
	else if (checkXRatio > checkYRatio)
	{
		// 上下のフラグを残す
		ret = checkFlag & (AABB_UP | AABB_DOWN);
	}

	return ret;
}

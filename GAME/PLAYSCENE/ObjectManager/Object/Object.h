#pragma once
#include"../../../Utility.h"
#include"../../BoxCollider/BoxCollider.h"

class Object
{
public:

	virtual ~Object() = default;

	virtual void Initialize(float x,float y,float sizex,float sizey) = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Finalize() = 0;

	virtual Float2 GetPos() = 0;

	virtual BoxCollider CheckHit() = 0;

	virtual float SizeX() = 0;
	virtual float SizeY() = 0;
};
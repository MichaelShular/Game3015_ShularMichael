#pragma once
#include "sceneNode.h"
#include "../../Common/MathHelper.h"

using namespace DirectX;

class Entity : public sceneNode
{
public:
	void setVelocity(XMFLOAT2 velocity);
	void setVelocity(float vx, float vy);
	XMFLOAT2 getVelocity() const;

	virtual	void updateCurrent(const GameTimer& gt);

public:
	XMFLOAT2 mVelocity;
};

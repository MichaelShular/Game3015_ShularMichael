#pragma once
#include "sceneNode.h"
#include "../../Common/MathHelper.h"

using namespace DirectX;

/// This class game object that are part of the world which could use velocity 
class Entity : public sceneNode
{
public:
	Entity(Game * game);
	void setVelocity(XMFLOAT2 velocity);
	void setVelocity(float vx, float vy);
	XMFLOAT2 getVelocity() const;

	virtual	void updateCurrent(const GameTimer& gt);

	

public:
	XMFLOAT2 mVelocity;
	Game* mGame;

};

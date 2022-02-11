#pragma once

#include "sceneNode.h"

/// This class is use to create game objects that are not affected by physics 
class SpriteNode : public sceneNode
{
public:
	SpriteNode();
private:
	virtual void drawCurrent() const;
private:
	std::string mSprite;
};
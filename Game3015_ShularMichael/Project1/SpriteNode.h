#pragma once

#include "sceneNode.h"

/// This class is use to create game objects that are not affected by physics 
class SpriteNode : public sceneNode
{
public:
	SpriteNode(Game* game);
	void buildSprite(std::string MatName, std::string GeoName);
private:
	virtual void drawCurrent() const;
private:
	std::string mSprite;
protected:
	Game* mGame;
};
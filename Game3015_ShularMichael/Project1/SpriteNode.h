#pragma once

#include "sceneNode.h"
#include "../../Common/d3dApp.h"

#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/d3dApp.h"
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

/// This class is use to create game objects that are not affected by physics 
class SpriteNode : public sceneNode
{
public:
	void ScrollTexture(XMFLOAT2 val);
	SpriteNode(Game* game);
	void buildSprite(std::string MatName, std::string GeoName);
private:
	virtual void drawCurrent() const;
private:
	std::string mSprite;
protected:
	
	Game* mGame;
};
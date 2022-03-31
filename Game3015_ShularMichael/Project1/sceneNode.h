#pragma once

#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "FrameResource.h"
#include "../../Common/GeometryGenerator.h"
#include "../../Common/d3dApp.h"
#include <vector>
#include <memory>

#include "Category.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

class Game;

struct Command;

/// This class is used manage transform hierarchies
class sceneNode
{
public:
	typedef std::unique_ptr<sceneNode> Ptr;
public:	
	sceneNode(Game* game);
	void attachChild(Ptr child);
	Ptr detachChild(const sceneNode& node);

	void update(const GameTimer& gt);
	XMFLOAT3 getWorldPosition();
	void setWorldPosition(float x, float y, float z) ;
	XMFLOAT3 getWorldRotation();
	void setWorldRotation(float x, float y, float z) ;
	XMFLOAT3 getWorldScale() ;
	void setWorldScale(float x, float y, float z);

	void onCommand(const Command& command, const GameTimer& gt);
	virtual unsigned int getCategory() const;
	
	virtual void draw() const;
private:
	virtual void updateCurrent(const GameTimer& gt);
	void updateChildren(const GameTimer& gt);

	
	virtual void drawCurrent() const;
	void drawChildren() const;
protected:
	Game* mGame;

private:
	std::vector<Ptr> mChildren;
	sceneNode* mParent;
	XMFLOAT3 mWorldPosition = {0,0,0};
	XMFLOAT3 mWorldRotation = { 0,0,0 };
	XMFLOAT3 mWorldScale = { 1,1,1 };
};

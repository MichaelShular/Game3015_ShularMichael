#pragma once

#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "FrameResource.h"
#include "../../Common/GeometryGenerator.h"
#include "../../Common/d3dApp.h"
#include <vector>
#include <memory>

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

class sceneNode
{
public:
	typedef std::unique_ptr<sceneNode> Ptr;
public:
	sceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const sceneNode& node);

	void update(const GameTimer& gt);
	XMFLOAT3 getWorldPosition();
	void setWorldPosition(float x, float y, float z) ;
	XMFLOAT3 getWorldRotation();
	void setWorldRotation(float x, float y, float z) ;
	XMFLOAT3 getWorldScale() ;
	void setWorldScale(float x, float y, float z);
private:
	virtual void updateCurrent(const GameTimer& gt);
	void updateChildren(const GameTimer& gt);

	

	/*virtual void draw(const GameTimer& gt) const;
	virtual void drawCurrent(const GameTimer& gt) const;
	void drawChildren(const GameTimer& gt) const;*/
private:
	std::vector<Ptr> mChildren;
	sceneNode* mParent;
	XMFLOAT3 mWorldPosition = {0,0,0};
	XMFLOAT3 mWorldRotation = { 0,0,0 };
	XMFLOAT3 mWorldScale = { 1,1,1 };
};

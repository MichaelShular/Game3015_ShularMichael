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

// Lightweight structure stores parameters to draw a shape.  This will
// vary from app-to-app.
struct RenderItem
{
	RenderItem() = default;

	// World matrix of the shape that describes the object's local space
	// relative to the world space, which defines the position, orientation,
	// and scale of the object in the world.
	XMFLOAT4X4 World = MathHelper::Identity4x4();

	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();

	// Dirty flag indicating the object data has changed and we need to update the constant buffer.
	// Because we have an object cbuffer for each FrameResource, we have to apply the
	// update to each FrameResource.  Thus, when we modify obect data we should set 
	// NumFramesDirty = gNumFrameResources so that each frame resource gets the update.
	int NumFramesDirty = gNumFrameResources;

	// Index into GPU constant buffer corresponding to the ObjectCB for this render item.
	UINT ObjCBIndex = -1;

	Material* Mat = nullptr;
	MeshGeometry* Geo = nullptr;

	// Primitive topology.
	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	// DrawIndexedInstanced parameters.
	UINT IndexCount = 0;
	UINT StartIndexLocation = 0;
	int BaseVertexLocation = 0;
};

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

	XMFLOAT4X4 getWorldTransform() const;
	XMFLOAT4X4 getTransform() const;


	void onCommand(const Command& command, const GameTimer& gt);
	virtual unsigned int getCategory() const;
	
	virtual void draw() const;

	void move(float x, float y, float z);
private:
	virtual void updateCurrent(const GameTimer& gt);
	void updateChildren(const GameTimer& gt);

	
	virtual void drawCurrent() const;
	void drawChildren() const;
protected:
	Game* mGame;
	RenderItem* renderer;
	XMFLOAT2 mTexturePosition; 
private:
	std::vector<Ptr> mChildren;
	sceneNode* mParent;
	XMFLOAT3 mWorldPosition = {0,0,0};
	XMFLOAT3 mWorldRotation = { 0,0,0 };
	XMFLOAT3 mWorldScale = { 1,1,1 };
};

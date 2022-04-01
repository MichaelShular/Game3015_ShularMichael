#include "sceneNode.h"
#include "Game.h"
#include "Command.h"
#include <algorithm>
#include <cassert>

/// The defualt conconstructor
sceneNode::sceneNode(Game * game)
	: mChildren()
	, mParent(nullptr)
{
	mGame = game;
}
/// Used attach game objects to sceneNode
/// 
/// @param: std::unique_ptr<sceneNode>
void sceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}
/// Used detach game objects from sceneNode
/// 
/// @param: const sceneNode&
sceneNode::Ptr sceneNode::detachChild(const sceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}
/// Used to update
/// 
/// @param: const GameTimer&
void sceneNode::update(const GameTimer& gt)
{
	updateCurrent(gt);
	updateChildren(gt);
}
/// Used to update
/// 
/// @param: const GameTimer&
void sceneNode::updateCurrent(const GameTimer& gt)
{
	// Do nothing by default
}
/// Used to update all childern in sceneNode
/// 
/// @param: const GameTimer&
void sceneNode::updateChildren(const GameTimer& gt)
{
	for (Ptr& child : mChildren)
	{
		child->update(gt);
	}
}
/// Used to draw all childern in sceneNode
void sceneNode::draw() const
{

	// Draw node and children with changed transform
	drawCurrent();
	drawChildren();
}
/// Move the game object position
/// 
/// @param: float x
/// @param: float x
/// @param: float z
void sceneNode::move(float x, float y, float z)
{
	setWorldPosition(getWorldPosition().x + x, getWorldPosition().y + y, getWorldPosition().z + z);
}

/// Used to draw
void sceneNode::drawCurrent() const
{
	// Do nothing by default
}
/// Used to draw the children
void sceneNode::drawChildren() const
{
	for (const Ptr& child : mChildren)
		child->draw();
}


/// Used to get game object's world position
/// 
/// @returns DirectX::XMFLOAT3
XMFLOAT3 sceneNode::getWorldPosition()
{
	return mWorldPosition;
}
/// Used to set game object's world position
/// 
/// @param: a float for x position
/// @param: a float for y position
/// @param: a float for z position
void sceneNode::setWorldPosition(float x, float y, float z)
{
	mWorldPosition.x = x;
	mWorldPosition.y = y;
	mWorldPosition.z = z;
}
/// Used to get game object's world rotatiion
/// 
/// @returns DirectX::XMFLOAT3
XMFLOAT3 sceneNode::getWorldRotation()
{
	return mWorldRotation;
}
/// Used to set game object's world rotatiion
/// 
/// @param: a float for x rotatiion
/// @param: a float for y rotatiion
/// @param: a float for z rotatiion
void sceneNode::setWorldRotation(float x, float y, float z)
{
	mWorldRotation.x = x;
	mWorldRotation.y = y;
	mWorldRotation.z = z;
}
/// Used to get game object's world scale
/// 
/// @returns DirectX::XMFLOAT3
XMFLOAT3 sceneNode::getWorldScale()
{
	return mWorldScale;
}
/// Used to set game object's world scale
/// 
/// @param: a float for x scale
/// @param: a float for y scale
/// @param: a float for z scale
void sceneNode::setWorldScale(float x, float y, float z)
{
	mWorldScale.x = x;
	mWorldScale.y = y;
	mWorldScale.z = z;
}

/// Used to get the world transform
/// 
/// @return: XMFLOAT4X4
XMFLOAT4X4 sceneNode::getWorldTransform() const 
{
	XMFLOAT4X4 transform = MathHelper::Identity4x4();
	XMMATRIX T = XMLoadFloat4x4(&transform);
	for (const sceneNode* node = this; node != nullptr; node = node->mParent) 
	{
		XMMATRIX Tp = XMLoadFloat4x4(&node->getTransform());
		T = Tp * T;
	}
	XMStoreFloat4x4(&transform, T);

	return transform;
}
/// Used to get the objects transforms
/// 
/// @return: XMFLOAT4X4
XMFLOAT4X4 sceneNode::getTransform() const
{
	XMFLOAT4X4 transform;

	XMMATRIX T(XMMatrixTranslation(mWorldPosition.x, mWorldPosition.y, mWorldPosition.z) 
		* XMMatrixRotationX(XMConvertToRadians(mWorldRotation.x))
			* XMMatrixRotationY(XMConvertToRadians(mWorldRotation.y))
				* XMMatrixRotationZ(XMConvertToRadians(mWorldRotation.z))
					* XMMatrixScaling(mWorldScale.x, mWorldScale.y, mWorldScale.z));

	//*XMMatrixRotationX(XMConvertToRadians(mWorldRotation.x))
	//	* XMMatrixRotationY(XMConvertToRadians(mWorldRotation.y))
	//	* XMMatrixRotationZ(XMConvertToRadians(mWorldRotation.z))
	XMStoreFloat4x4(&transform, T);

	return transform;
}

/// Used to run actions base on command
/// 
/// @param:  Command&
/// @param:  GameTimer&
void sceneNode::onCommand(const Command& command, const GameTimer& gt)
{
	// Command current node, if category matches
	if (command.category & getCategory())
		command.action(*this, gt) ;

	// Command children
	for (Ptr& child : mChildren)
		child->onCommand(command, gt);
}
/// Used get the catefgory
/// 
/// @return:  Command&
unsigned int sceneNode::getCategory() const
{
	return Category::Scene;
}

#include "sceneNode.h"
#include "Game.h"
#include <algorithm>
#include <cassert>



sceneNode::sceneNode()
	: mChildren()
	, mParent(nullptr)
{

}

void sceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

sceneNode::Ptr sceneNode::detachChild(const sceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void sceneNode::update(const GameTimer& gt)
{
	updateCurrent(gt);
	updateChildren(gt);
}

void sceneNode::updateCurrent(const GameTimer& gt)
{
	// Do nothing by default
}

void sceneNode::updateChildren(const GameTimer& gt)
{
	for (Ptr& child : mChildren)
	{
		child->update(gt);
	}
}

XMFLOAT3 sceneNode::getWorldPosition()
{
	return mWorldPosition;
}

void sceneNode::setWorldPosition(float x, float y, float z)
{
	mWorldPosition.x = x;
	mWorldPosition.y = y;
	mWorldPosition.z = z;
}

XMFLOAT3 sceneNode::getWorldRotation()
{
	return mWorldRotation;
}

void sceneNode::setWorldRotation(float x, float y, float z)
{
	mWorldRotation.x = x;
	mWorldRotation.y = y;
	mWorldRotation.z = z;
}

XMFLOAT3 sceneNode::getWorldScale()
{
	return mWorldScale;
}

void sceneNode::setWorldScale(float x, float y, float z)
{
	mWorldScale.x = x;
	mWorldScale.y = y;
	mWorldScale.z = z;
}


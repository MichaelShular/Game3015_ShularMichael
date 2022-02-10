#include "sceneNode.h"
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


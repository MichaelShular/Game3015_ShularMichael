#pragma once

#include "../../Common/d3dApp.h"
#include <vector>
#include <memory>

class sceneNode
{
public:
	typedef std::unique_ptr<sceneNode> Ptr;
public:
	sceneNode();
private:
	void attachChild(Ptr child);
	Ptr detachChild(const sceneNode& node);

	void update(const GameTimer& gt);

	virtual void updateCurrent(const GameTimer& gt);
	void updateChildren(const GameTimer& gt);

	/*virtual void draw(const GameTimer& gt) const;
	virtual void drawCurrent(const GameTimer& gt) const;
	void drawChildren(const GameTimer& gt) const;*/
private:
	std::vector<Ptr> mChildren;
	sceneNode* mParent;
};

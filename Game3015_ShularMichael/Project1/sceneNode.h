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
	void attachChild(Ptr child);
	Ptr detachChild(const sceneNode& node);

	void update(const GameTimer& gt);
private:
	
	

	virtual void updateCurrent(const GameTimer& gt);
	void updateChildren(const GameTimer& gt);

	XMFLOAT3 getWorldPosition() const;
	void setWorldPosition(float x, float y, float z) ;
	XMFLOAT3 getWorldRotation() const;
	void setWorldRotation(float x, float y, float z) ;
	XMFLOAT3 getWorldScale() const;
	void setWorldScale(float x, float y, float z);

	/*virtual void draw(const GameTimer& gt) const;
	virtual void drawCurrent(const GameTimer& gt) const;
	void drawChildren(const GameTimer& gt) const;*/
private:
	std::vector<Ptr> mChildren;
	sceneNode* mParent;
	XMFLOAT3 mWorldPosition;
	XMFLOAT3 mWorldRotation;
	XMFLOAT3 mWorldScale;
};

#ifndef BOOK_MENUSTATE_H
#define BOOK_MENUSTATE_H

#include "State.h"
#include "../../Common/d3dApp.h"
#include "../../Common/d3dApp.h"
#include "SpriteNode.h"
#include "sceneNode.h"

///This class is the derived class from state, which is used to stop gameplay
class MenuState : public State
{
public:
	MenuState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(const GameTimer& gt);
	virtual bool handleEvent();
	virtual void BuildScene();
private:
	sceneNode* sceneGraph;
	SpriteNode* mBackgroundSprite;
};

#endif // BOOK_MENUSTATE_HPP

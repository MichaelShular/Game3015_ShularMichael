#ifndef BOOK_TITLESTATE_H
#define BOOK_TITLESTATE_H

#include "State.h"
#include "../../Common/d3dApp.h"
#include "SpriteNode.h"
#include "sceneNode.h"
//#include "World.h"
//#include "Player.h"

class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(const GameTimer& gt);
	virtual bool		handleEvent();
	virtual void		BuildScene();

private:

	/*World* mWorld;
	Player& mPlayer;*/
	sceneNode* sceneGraph;
	SpriteNode* mBackgroundSprite;
	/*sf::Text			mText;

	bool				mShowText;
	sf::Time			mTextEffectTime;*/
};

#endif // BOOK_TITLESTATE_HPP

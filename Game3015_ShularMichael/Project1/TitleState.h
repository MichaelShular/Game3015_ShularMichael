#ifndef BOOK_TITLESTATE_H
#define BOOK_TITLESTATE_H

#include "State.h"
#include "../../Common/d3dApp.h"
#include "SpriteNode.h"


class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(const GameTimer& gt);
	virtual bool		handleEvent();


private:
	SpriteNode* mBackgroundSprite;
	/*sf::Text			mText;

	bool				mShowText;
	sf::Time			mTextEffectTime;*/
};

#endif // BOOK_TITLESTATE_HPP

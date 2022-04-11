#ifndef BOOK_TITLESTATE_HPP
#define BOOK_TITLESTATE_HPP

#include "State.h"
#include "../../Common/d3dApp.h"


class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context, Game* game);

	virtual void		draw();
	virtual bool		update(const GameTimer& gt);
	virtual bool		handleEvent();


private:
	/*sf::Sprite			mBackgroundSprite;
	sf::Text			mText;

	bool				mShowText;
	sf::Time			mTextEffectTime;*/
};

#endif // BOOK_TITLESTATE_HPP

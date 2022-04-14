#ifndef BOOK_PAUSESTATE_H
#define BOOK_PAUSESTATE_H

#include "State.h"
#include "../../Common/d3dApp.h"
#include "../../Common/d3dApp.h"
#include "SpriteNode.h"
#include "sceneNode.h"

class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(const GameTimer& gt);
	virtual bool			handleEvent();
	virtual void			BuildScene();
	void					updateOptionText();


private:
	sceneNode* pauseSceneGraph;
	SpriteNode* mPauseSprite;

private:
	//sf::Sprite				mBackgroundSprite;

	//std::vector<sf::Text>	mOptions;
	//std::size_t				mOptionIndex;
};

#endif // BOOK_PAUSESTATE_HPP

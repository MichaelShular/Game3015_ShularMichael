#ifndef BOOK_MENUSTATE_H
#define BOOK_MENUSTATE_H

#include "State.h"
#include "../../Common/d3dApp.h"
#include "../../Common/d3dApp.h"
#include "SpriteNode.h"
#include "sceneNode.h"

class MenuState : public State
{
public:
	MenuState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(const GameTimer& gt);
	virtual bool			handleEvent();
	virtual void			BuildScene();
	void					updateOptionText();


private:
	enum OptionNames
	{
		Play,
		Exit,
	};
	sceneNode* sceneGraph;
	SpriteNode* mBackgroundSprite;

private:
	//sf::Sprite				mBackgroundSprite;

	//std::vector<sf::Text>	mOptions;
	//std::size_t				mOptionIndex;
};

#endif // BOOK_MENUSTATE_HPP

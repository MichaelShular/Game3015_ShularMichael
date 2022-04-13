#ifndef BOOK_GAMESTATE_H
#define BOOK_GAMESTATE_H

#include "State.h"
#include "World.h"
#include "Player.h"


class GameState : public State
{
public:
	GameState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(const GameTimer& gt);
	virtual bool handleEvent();
	void BuildScene();

private:
	World* mWorld;
	Player& mPlayer;
};

#endif // BOOK_GAMESTATE_HPP
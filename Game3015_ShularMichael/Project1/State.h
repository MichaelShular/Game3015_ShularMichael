#ifndef BOOK_STATE_HPP
#define BOOK_STATE_HPP

#include "StateIdentifiers.h"
//#include "ResourceIdentifiers.h"
#include "../../Common/d3dApp.h"

//#include <SFML/System/Time.hpp>
//#include <SFML/Window/Event.hpp>

#include <memory>


class StateStack;
class Player;
class Game;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
		Context(Player& player, Game * game);
		
		Player* player;
		Game* mGame;
	};


public:
	State(StateStack& stack, Context context);
	virtual				~State();

	virtual void draw() = 0;
	virtual bool update(const GameTimer& gt) = 0;
	virtual bool handleEvent() = 0;
	Game* mGame;

protected:
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStateClear();

	Context getContext() const;

	StateStack* mStack;
private:
	
	Context mContext;
};

#endif // BOOK_STATE_HPP

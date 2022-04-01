#pragma once
#include "Command.h"

#include "map"

class CommandQueue;

class Player
{
public:
	Player();
	void handleEvent(CommandQueue& commands, int key);
	void handleRealtimeInput(CommandQueue& commands, int key);
#pragma region step 1
	//static const float		PlayerSpeed;
	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount
	};


private:
	void initializeActions();
	static bool isRealtimeAction(Action action);


private:
	std::map<int, Action> mKeyBinding;
	std::map<Action, Command> mActionBinding;
#pragma endregion


};
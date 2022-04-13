#include "GameState.h"
#include "Game.h"

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mWorld(&(mGame->mGameWorld))
	, mPlayer(*context.player)
{
	BuildScene();
}

void GameState::draw()
{
	mWorld->draw();
}

bool GameState::update(const GameTimer& gt)
{
	mWorld->update(gt);

	CommandQueue& commands = mWorld->getCommandQueue();
	mPlayer.handleRealtimeInput(commands);

	return true;
}

bool GameState::handleEvent()
{
	// Game input handling
	CommandQueue& commands = mWorld->getCommandQueue();
	mPlayer.handleEvent(commands, 46);
	mPlayer.handleRealtimeInput(commands);
//	// Escape pressed, trigger the pause screen
//#pragma region step 1
//	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//		requestStackPush(States::Pause);
//#pragma endregion
	return true;
}

void GameState::BuildScene()
{
	mWorld->buildScene();


	mGame->BuildFrameResources();
	
}


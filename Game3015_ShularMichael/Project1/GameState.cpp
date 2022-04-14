#include "GameState.h"
#include "Game.h"

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mWorld(&(mGame->mGameWorld))
	, mPlayer(*context.player),
	mPauseSprite(nullptr),
	pauseSceneGraph(new sceneNode(mGame))
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
//#pragma endregionif 
#pragma region
	if(GetAsyncKeyState('P') & 0x8000)
	{
		requestStackPush(States::Pause);
		mGame->gamePaused = true;
	}
#pragma endregion
	return true;
}

void GameState::BuildScene()
{
	mGame->mAllRitems.clear();
	mGame->mFrameResources.clear();
	mGame->mRitemLayer[(int)RenderLayer::AlphaTested].clear();

	mGame->mTexture.clear();
	mGame->loadTextures();

	mWorld->buildScene();
	
	std::unique_ptr<SpriteNode> BGSky(new SpriteNode(mGame));
	mPauseSprite = BGSky.get();
	mPauseSprite->setWorldPosition(-9.0f, -4.0f, 1.7f);
	mPauseSprite->setWorldRotation(90.0f, 13.0f, 45.0f);
	mPauseSprite->setWorldScale(0.1f, 0.5f, 0.5f);
	pauseSceneGraph->attachChild(std::move(BGSky));
	mPauseSprite->buildSpriteOpaque("pause", "box");


	mGame->BuildFrameResources();
	
}


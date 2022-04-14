#include "MenuState.h"
#include "Game.h"

/// The defualt conconstructor
/// 
/// @param: StateStack&
/// @param: Context 
MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context),
	sceneGraph(new sceneNode(mGame))
{
	BuildScene();
}

/// Used draw state's game objects
void MenuState::draw()
{
	sceneGraph->draw();
}

/// Used to keep game paused
/// 
/// @param: const GameTimer&
bool MenuState::update(const GameTimer& gt)
{
	sceneGraph->update(gt);
	return true;
}

///Handle any commands once or real time input
bool MenuState::handleEvent()
{
	//Game Scene
	if (GetAsyncKeyState(VK_RETURN ) & 0x8000)
	{
		requestStackPop();
		mGame->FlushCommandList();
		requestStackPush(States::Game);
	}
	//Quit Game
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		requestStackPop();
	}
	return true;
}

///Build game objects for scene (Not used)
void MenuState::BuildScene()
{
	mGame->mAllRitems.clear();
	mGame->mFrameResources.clear();
	mGame->mRitemLayer[(int)RenderLayer::AlphaTested].clear();
	
	mGame->mTexture.clear();
	mGame->loadTextures();

	mGame->BuildMaterials("title");
	mGame->BuildMaterials("sky");


	std::unique_ptr<SpriteNode> BGSky(new SpriteNode(mGame));
	mBackgroundSprite = BGSky.get();
	mBackgroundSprite->setWorldPosition(7.0f, 11.0f, -3.6f);
	mBackgroundSprite->setWorldRotation(90.0f, 13.0f, 45.0f);
	mBackgroundSprite->setWorldScale(0.1f, 10.0f, 14.0f);
	sceneGraph->attachChild(std::move(BGSky));
	mBackgroundSprite->buildSprite("sky", "box");

	mGame->BuildFrameResources();
}

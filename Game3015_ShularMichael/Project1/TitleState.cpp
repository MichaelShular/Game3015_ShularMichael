#include "TitleState.h"
#include "Game.h"

/// The defualt conconstructor
/// 
/// @param: StateStack&
/// @param: Context 
TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context),
	sceneGraph(new sceneNode(mGame))
{
	BuildScene();
}

/// Used draw state's game objects
void TitleState::draw()
{
	sceneGraph->draw();
}

/// Used to keep game paused
/// 
/// @param: const GameTimer&
bool TitleState::update(const GameTimer& gt)
{
	sceneGraph->update(gt);

	return true;
}

///Handle any commands once or real time input
bool TitleState::handleEvent()
{
	//Open Game menu
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{		
		requestStackPop();
		mGame->FlushCommandList();
		requestStackPush(States::Menu);
	}

	return true;
}

///Build game objects for scene
void TitleState::BuildScene()
{
	mGame->BuildMaterials("title");

	std::unique_ptr<SpriteNode> BGSky(new SpriteNode(mGame));
	mBackgroundSprite = BGSky.get();
	mBackgroundSprite->setWorldPosition(7.0f, 11.0f, -3.6f);
	mBackgroundSprite->setWorldRotation(90.0f, 13.0f, 45.0f);
	mBackgroundSprite->setWorldScale(0.1f, 10.0f, 14.0f);
	sceneGraph->attachChild(std::move(BGSky));
	mBackgroundSprite->buildSprite("title", "box");

	mGame->BuildFrameResources();
}

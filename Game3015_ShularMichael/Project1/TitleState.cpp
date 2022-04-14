#include "TitleState.h"
#include "Game.h"

TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context),
	sceneGraph(new sceneNode(mGame))
	/*, mWorld(&(mGame->mGameWorld))
	, mPlayer(*context.player)*/
{
	//mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	/*mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Press any key to start");
	centerOrigin(mText);
	mText.setPosition(context.window->getView().getSize() / 2.f);*/

	BuildScene();
}

void TitleState::draw()
{
	sceneGraph->draw();
	/*sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
		window.draw(mText);*/
}

bool TitleState::update(const GameTimer& gt)
{

	sceneGraph->update(gt);
	//CommandQueue& commands = mWorld->getCommandQueue();
	//mPlayer.handleRealtimeInput(commands);

	return true;
}

bool TitleState::handleEvent()
{
	// If any key is pressed, trigger the next screen
	/*CommandQueue& commands = mWorld->getCommandQueue();
	mPlayer.handleEvent(commands, 46);
	mPlayer.handleRealtimeInput(commands);*/
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{

		
		requestStackPop();
		mGame->FlushCommandList();
		requestStackPush(States::Menu);
	}

	return true;
}

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

#include "PauseState.h"
#include "Game.h"

PauseState::PauseState(StateStack& stack, Context context)
	: State(stack, context),
	sceneGraph(new sceneNode(mGame))
	//, mOptions()
	//, mOptionIndex(0)
{
	//sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	//sf::Font& font = context.fonts->get(Fonts::Main);

	//mBackgroundSprite.setTexture(texture);

	//// A simple menu demonstration
	//sf::Text playOption;
	//playOption.setFont(font);
	//playOption.setString("Play");
	//centerOrigin(playOption);
	//playOption.setPosition(context.window->getView().getSize() / 2.f);
	//mOptions.push_back(playOption);

	//sf::Text exitOption;
	//exitOption.setFont(font);
	//exitOption.setString("Exit");
	//centerOrigin(exitOption);
	//exitOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 30.f));
	//mOptions.push_back(exitOption);

	//updateOptionText();

	BuildScene();
}

void PauseState::draw()
{
	sceneGraph->draw();
	/*sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

	for (const sf::Text& text : mOptions)
		window.draw(text);*/
}

bool PauseState::update(const GameTimer& gt)
{
	
	return false;
}

bool PauseState::handleEvent()
{
	//Quit Game
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		requestStackPop();
	}

	//// The demonstration menu logic
	//if (event.type != sf::Event::KeyPressed)
	//	return false;

	//if (event.key.code == sf::Keyboard::Return)
	//{
	//	if (mOptionIndex == Play)
	//	{
	//		requestStackPop();
	//		requestStackPush(States::Game);
	//	}
	//	else if (mOptionIndex == Exit)
	//	{
	//		// The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
	//		requestStackPop();
	//	}
	//}

	//else if (event.key.code == sf::Keyboard::Up)
	//{
	//	// Decrement and wrap-around
	//	if (mOptionIndex > 0)
	//		mOptionIndex--;
	//	else
	//		mOptionIndex = mOptions.size() - 1;

	//	updateOptionText();
	//}

	//else if (event.key.code == sf::Keyboard::Down)
	//{
	//	// Increment and wrap-around
	//	if (mOptionIndex < mOptions.size() - 1)
	//		mOptionIndex++;
	//	else
	//		mOptionIndex = 0;

	//	updateOptionText();
	//}

	return true;
}

void PauseState::BuildScene()
{
	/*mGame->mAllRitems.clear();
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

	mGame->BuildFrameResources();*/
}

void PauseState::updateOptionText()
{
	//if (mOptions.empty())
	//	return;

	//// White all texts
	//for (sf::Text& text : mOptions)
	//	text.setFillColor(sf::Color::White);

	//// Red the selected text
	//mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}

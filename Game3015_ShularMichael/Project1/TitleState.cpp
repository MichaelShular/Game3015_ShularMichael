#include "TitleState.h"


TitleState::TitleState(StateStack& stack, Context context, Game& game)
	: State(stack, context, game)
	/*, mText()
	, mShowText(true)
	, mTextEffectTime(sf::Time::Zero)*/
{
	/*mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Press any key to start");
	centerOrigin(mText);
	mText.setPosition(context.window->getView().getSize() / 2.f);*/
}

void TitleState::draw()
{
	/*sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
		window.draw(mText);*/
}

bool TitleState::update(const GameTimer& gt)
{
	/*mTextEffectTime += gt;

	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}*/

	return true;
}

bool TitleState::handleEvent()
{
	//// If any key is pressed, trigger the next screen
	//if (event.type == sf::Event::KeyPressed)
	//{
	//	requestStackPop();
	//	requestStackPush(States::Menu);
	//}

	return true;
}
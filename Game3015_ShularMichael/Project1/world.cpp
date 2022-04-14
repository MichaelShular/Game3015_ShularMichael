#include "world.h"
#include "Game.h"
/// The defualt conconstructor
///
/// @param: Game
World::World(Game* game) :
	sceneGraph(new sceneNode(game)),
	mGame(game)
{


}

/// USed to get the command queue
/// 
/// @returns CommandQueue&
CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}


/// Used update sceneNode class
/// 
/// @param: const GameTimer&
void World::update(const GameTimer& gt)
{
	mplayerAircraftOne->setVelocity(0, 0);


	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		sceneGraph->onCommand(mCommandQueue.pop(), gt);



	sceneGraph->update(gt);
	//mGround->ScrollTexture(XMFLOAT2(0, -0.1f * gt.DeltaTime()) );
	
}
/// Used draw
/// 
/// @param: const GameTimer&
void World::draw()
{
	sceneGraph->draw();
}
/// Used to pass information about textures to game 
/// 
/// @returns &std::unordered_map<std::string, std::wstring>
std::unordered_map<std::string, std::wstring>* World::getTextures()
{
	return &mTexture;
}
/// Used to construct materials for scene and game objects
void World::buildScene()
{
	mGame->BuildMaterials("title");
	mGame->BuildMaterials("sky");
	mGame->BuildMaterials("desert");
	mGame->BuildMaterials("eagle");
	mGame->BuildMaterials("raptor");
	mGame->BuildMaterials("pause");



	std::unique_ptr<SpriteNode> BGSky(new SpriteNode(mGame));
	mSky = BGSky.get();
	mSky->setWorldPosition(2.0f, 15.0f, 0.f);
	mSky->setWorldRotation(90.0f, 0.0f, 0.0f);
	mSky->setWorldScale(0.1f, 30.0f, 30.0f);

	/*mSky->setWorldPosition(0.0f, 0.0f, 0.f);
	mSky->setWorldRotation(90.0f, 0.0f, 0.0f);
	mSky->setWorldScale(0.1f, 30.0f, 30.0f);*/


	sceneGraph->attachChild(std::move(BGSky));
	mSky->buildSprite("sky", "box");

	//mGame->BuildRenderItems("sky", "box", mSky->getWorldPosition(), mSky->getWorldRotation(), mSky->getWorldScale());
	std::unique_ptr<SpriteNode> BGGround(new SpriteNode(mGame));
	mGround = BGGround.get();
	mGround->setWorldPosition(0.0f, 10.0f, -5.0f);
	mGround->setWorldRotation(0.0f, 0.0f, 0.0f);
	mGround->setWorldScale(30.0f, 30.0f, 0.1f);
	/*mGround->setWorldPosition(0.0f, 0.0f, 0.0f);
	mGround->setWorldRotation(0.0f, 0.0f, 0.0f);
	mGround->setWorldScale(30.0f, 30.0f, 0.1f);*/

	//mGame->BuildRenderItems("desert", "box", mGround->getWorldPosition(), mGround->getWorldRotation(), mGround->getWorldScale());
	mGround->buildSprite("desert", "box");

	sceneGraph->attachChild(std::move(BGGround));





	/*std::unique_ptr<Aircraft> eaglePlane(new Aircraft(Aircraft::Eagle, mGame));
	mplayerAircraftOne = eaglePlane.get();
		mplayerAircraftOne->setWorldPosition(0.7f, -1.5f, 0.6f);
	mplayerAircraftOne->setWorldRotation(0.0f, 1.0f, 0.2f);
	mplayerAircraftOne->setWorldScale(0.05f, 0.05f, 0.0f);
	sceneGraph->attachChild(std::move(eaglePlane));

	mGame->BuildRenderItems("eagle", "box", mplayerAircraftOne->getWorldPosition(), mplayerAircraftOne->getWorldRotation(), mplayerAircraftOne->getWorldScale());*/

	//std::unique_ptr<Aircraft> raptorPlane(new Aircraft(Aircraft::Raptor, mGame));
	//mplayerAircraftTwo = raptorPlane.get();
	//mplayerAircraftTwo->setWorldPosition(0.3f, -1.6f, 0.4f);
	//mplayerAircraftTwo->setWorldRotation(0.0f, 1.0f, 0.1f);
	//mplayerAircraftTwo->setWorldScale(0.05f, 0.05f, 0.0f);
	//sceneGraph->attachChild(std::move(raptorPlane));

	//mGame->BuildRenderItems("raptor", "box", mplayerAircraftTwo->getWorldPosition(), mplayerAircraftTwo->getWorldRotation(), mplayerAircraftTwo->getWorldScale());





	std::unique_ptr<Aircraft> eaglePlane(new Aircraft(Aircraft::Eagle, mGame));
	mplayerAircraftOne = eaglePlane.get();
	mplayerAircraftOne->setWorldPosition(0.4f, -1.5f, 0.6f);
	mplayerAircraftOne->setWorldRotation(0.0f, 0.0f, 0.0f);
	mplayerAircraftOne->setWorldScale(0.0f, 0.55f, 0.55f);

	mplayerAircraftOne->buildAircraft();
	sceneGraph->attachChild(std::move(eaglePlane));
}
///// Used get set all information for textures
//void World::loadTextures()
//{
//	CreateTexture("desert", L"Desert.dds");
//	CreateTexture("sky", L"sky.dds");
//	CreateTexture("eagle", L"Eagle.dds");
//	CreateTexture("raptor", L"Raptor.dds");
//}
///// Used save information about textures name and file path
///// 
///// @param: std::string
///// @param: std::wstring
//void World::CreateTexture(std::string name, std::wstring fileName)
//{
//	mTexture[name] = fileName;
//}

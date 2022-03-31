#include "world.h"
#include "Game.h"
/// The defualt conconstructor
///
/// @param: Game
World::World(Game* game):
	sceneGraph(new sceneNode(game))
{
	mGame = game;
	loadTextures();
}


CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}


/// Used update sceneNode class
/// 
/// @param: const GameTimer&
void World::update(const GameTimer& gt)
{

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		sceneGraph->onCommand(mCommandQueue.pop(), gt);


	sceneGraph->update(gt);
}
/// Used draw
/// 
/// @param: const GameTimer&
void World::draw(const GameTimer& gt)
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
	mGame->BuildMaterials("desert");
	mGame->BuildMaterials("sky");
	mGame->BuildMaterials("eagle");
	mGame->BuildMaterials("raptor");

	std::unique_ptr<SpriteNode> BGGround(new SpriteNode(mGame));
	mGround = BGGround.get();
	mGround->setWorldPosition(0.0f, 0.0f, 0.0f);
	mGround->setWorldRotation(0.0f, 0.0f, 0.0f);
	mGround->setWorldScale(2.0f, 2.5f, 0.0f);
	mGame->BuildRenderItems("desert", "box", mGround->getWorldPosition(), mGround->getWorldRotation(), mGround->getWorldScale());
	sceneGraph->attachChild(std::move(BGGround));

	std::unique_ptr<SpriteNode> BGSky(new SpriteNode(mGame));
	mSky = BGSky.get();
	mSky->setWorldPosition(1.0f, 0.0f, 0.5f);
	mSky->setWorldRotation(1.57f, 0.0f, 0.0f);
	mSky->setWorldScale(0.0f, 2.0f, 2.5f);
	sceneGraph->attachChild(std::move(BGSky));

	mGame->BuildRenderItems("sky", "box", mSky->getWorldPosition(), mSky->getWorldRotation(), mSky->getWorldScale());

	std::unique_ptr<Aircraft> eaglePlane(new Aircraft(Aircraft::Eagle, mGame));
	mplayerAircraftOne = eaglePlane.get();
	mplayerAircraftOne->setWorldPosition(0.7f, -1.5f, 0.6f);
	mplayerAircraftOne->setWorldRotation(0.0f, 1.0f, 0.2f);
	mplayerAircraftOne->setWorldScale(0.05f, 0.05f, 0.0f);
	sceneGraph->attachChild(std::move(eaglePlane));

	mGame->BuildRenderItems("eagle", "box", mplayerAircraftOne->getWorldPosition(), mplayerAircraftOne->getWorldRotation(), mplayerAircraftOne->getWorldScale());

	std::unique_ptr<Aircraft> raptorPlane(new Aircraft(Aircraft::Eagle, mGame));
	mplayerAircraftTwo = raptorPlane.get();
	mplayerAircraftTwo->setWorldPosition(0.3f, -1.6f, 0.4f);
	mplayerAircraftTwo->setWorldRotation(0.0f, 1.0f, 0.1f);
	mplayerAircraftTwo->setWorldScale(0.05f, 0.05f, 0.0f);
	sceneGraph->attachChild(std::move(raptorPlane));

	mGame->BuildRenderItems("raptor", "box", mplayerAircraftTwo->getWorldPosition(), mplayerAircraftTwo->getWorldRotation(), mplayerAircraftTwo->getWorldScale());
}
/// Used get set all information for textures
void World::loadTextures()
{
	CreateTexture("desert", L"Desert.dds");
	CreateTexture("sky", L"sky.dds");
	CreateTexture("eagle", L"Eagle.dds");
	CreateTexture("raptor", L"Raptor.dds");
}
/// Used save information about textures name and file path
/// 
/// @param: std::string
/// @param: std::wstring
void World::CreateTexture(std::string name, std::wstring fileName)
{
	mTexture[name] = fileName;
}

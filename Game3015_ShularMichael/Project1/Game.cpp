#include "Game.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

Game::Game(HINSTANCE hInstance) : D3DApp(hInstance)
{

}

Game::~Game()
{
	if (md3dDevice != nullptr)
		FlushCommandQueue();
}

bool Game::Initialize() {
	if (!D3DApp::Initialize())
		return false;

	return true;
}

void Game::Update(const GameTimer& gt)
{
}

void Game::Draw(const GameTimer& gt)
{
}

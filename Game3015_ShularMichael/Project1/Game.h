#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "FrameResource.h"
#include "../../Common/GeometryGenerator.h"
#include "world.h"
#include "Player.h"
#include "StateStack.h"
using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")



//step1
enum class RenderLayer : int
{
	Opaque = 0,
	AlphaTested,
	Count
};

/// This class is used to Initialize the application, control game loop and hold the D3D12 game engine function.  
class Game : public D3DApp
{
public:
	Game(HINSTANCE hInstance);

public:
	Game(const Game& rhs) = delete;
	Game& operator=(const Game& rhs) = delete;
	~Game();

	virtual bool Initialize()override;

public:
	virtual void OnResize()override;
	virtual void Update(const GameTimer& gt)override;
	virtual void Draw(const GameTimer& gt)override;

	virtual void OnMouseDown(WPARAM btnState, int x, int y)override;
	virtual void OnMouseUp(WPARAM btnState, int x, int y)override;
	virtual void OnMouseMove(WPARAM btnState, int x, int y)override;

	void OnKeyboardInput(const GameTimer& gt);
	void UpdateCamera(const GameTimer& gt);
	void AnimateMaterials(const GameTimer& gt);
	void UpdateObjectCBs(const GameTimer& gt);
	void UpdateMaterialCBs(const GameTimer& gt);
	void UpdateMainPassCB(const GameTimer& gt);
	void LoadTextures(std::string name, std::wstring fileName);
	void BuildRootSignature();
	void BuildDescriptorHeaps();
	void BuildShadersAndInputLayout();
	void BuildShapeGeometry(GeometryGenerator::MeshData box, std::string shapeName);
	void BuildPSOs();
	void BuildFrameResources();
	void BuildMaterials(std::string name);
	void BuildRenderItems(std::string matName, std::string geoName, XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale);
	void DrawRenderItems(ID3D12GraphicsCommandList* cmdList, const std::vector<RenderItem*>& ritems);

	std::array<const CD3DX12_STATIC_SAMPLER_DESC, 6> GetStaticSamplers();

	void processEvents();
	ID3D12GraphicsCommandList* getCmdList();

	void registerStates();
public:
	FrameResource* mCurrFrameResource = nullptr;

	World mGameWorld;

	std::vector<std::unique_ptr<FrameResource>> mFrameResources;

	int mCurrFrameResourceIndex = 0;

	UINT mCbvSrvDescriptorSize = 0;

	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;

	ComPtr<ID3D12DescriptorHeap> mSrvDescriptorHeap = nullptr;

	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
	std::unordered_map<std::string, std::unique_ptr<Material>> mMaterials;

	std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;

	std::unordered_map<std::string, ComPtr<ID3DBlob>> mShaders;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	//step2
	//ComPtr<ID3D12PipelineState> mOpaquePSO = nullptr;
	std::unordered_map<std::string, ComPtr<ID3D12PipelineState>> mPSOs;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;

	//step3
	// Render items divided by PSO.
	//std::vector<RenderItem*> mOpaqueRitems;
	std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	PassConstants mMainPassCB;

	XMFLOAT3 mEyePos = { 0.0f, 0.0f, 0.0f };
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.3f * XM_PI;
	float mPhi = 0.4f * XM_PI;
	float mRadius = 2.5f;

	POINT mLastMousePos;

	int MaterialCBIndexCount;
	int DiffuseSrvHeapIndexCount;
	int ObjectCBIndex;

	Player mPlayer;

	StateStack mStateStack;

	int key;
	int keyList[4] = { 66, 62, 44, 47 };
};

#endif 

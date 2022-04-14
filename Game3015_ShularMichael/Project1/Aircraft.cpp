#include "Aircraft.h"
#include "Game.h"
#include "../../Common/d3dApp.h"


/// The defualt conconstructor
/// 
/// @param: enum Type: use to switch sprites
/// @param: Game 
Aircraft::Aircraft(Type type, Game* game) : Entity(game)
{
	mGame = game;
	switch (type)
	{
	case Aircraft::Eagle:
		mSprite = "Eagle";
		break;
	case Aircraft::Raptor:
		mSprite = "Raptor";
		break;
	default:
		mSprite = "Eagle";
		break;
	}
}

/// Used to redraw game object
void Aircraft::drawCurrent() const
{
	UINT objCBByteSize = d3dUtil::CalcConstantBufferByteSize(sizeof(ObjectConstants));
	UINT matCBByteSize = d3dUtil::CalcConstantBufferByteSize(sizeof(MaterialConstants));

	auto objectCB = mGame->mCurrFrameResource->ObjectCB->Resource();
	auto matCB = mGame->mCurrFrameResource->MaterialCB->Resource();

	if (renderer != nullptr)
	{
		mGame->getCmdList()->IASetVertexBuffers(0, 1, &renderer->Geo->VertexBufferView());
		mGame->getCmdList()->IASetIndexBuffer(&renderer->Geo->IndexBufferView());
		mGame->getCmdList()->IASetPrimitiveTopology(renderer->PrimitiveType);

		CD3DX12_GPU_DESCRIPTOR_HANDLE tex(mGame->mSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
		tex.Offset(renderer->Mat->DiffuseSrvHeapIndex, mGame->mCbvSrvDescriptorSize);

		D3D12_GPU_VIRTUAL_ADDRESS objCBAddress = objectCB->GetGPUVirtualAddress() + (UINT64)renderer->ObjCBIndex * objCBByteSize;
		D3D12_GPU_VIRTUAL_ADDRESS matCBAddress = matCB->GetGPUVirtualAddress() +  (UINT64)renderer->Mat->MatCBIndex * matCBByteSize;

		mGame->getCmdList()->SetGraphicsRootDescriptorTable(0, tex);
		mGame->getCmdList()->SetGraphicsRootConstantBufferView(1, objCBAddress);
		mGame->getCmdList()->SetGraphicsRootConstantBufferView(3, matCBAddress);

		mGame->getCmdList()->DrawIndexedInstanced(renderer->IndexCount, 1, renderer->StartIndexLocation, renderer->BaseVertexLocation, 0);

	}

}
/// Get type of ship
/// 
/// @returns: enum Type: use to switch sprites
unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
	case Eagle:
		return Category::PlayerAircraft;

	default:
		return Category::EnemyAircraft;
	}
}
///Used to build the gameobject position, shape and material
void Aircraft::buildAircraft()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();

	renderer->World = getTransform();
	renderer->ObjCBIndex = mGame->mAllRitems.size();
	renderer->Mat = mGame->mMaterials["eagle"].get();
	renderer->Geo = mGame->mGeometries["box"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;

	mGame->mRitemLayer[(int)RenderLayer::AlphaTested].push_back(render.get());

	mGame->mAllRitems.push_back(std::move(render));

}

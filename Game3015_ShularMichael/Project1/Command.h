#pragma once
#include "Category.h"

#include "../../Common/d3dApp.h"


#include "functional"
#include "cassert"

class sceneNode;

struct Command
{
	Command();

	std::function<void(sceneNode&, const GameTimer&)> action;
	unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(sceneNode&, const GameTimer&)> derivedAction(Function fn)
{
	return [=](sceneNode& node, const GameTimer& gt)
	{
		// Check if cast is safe
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		// Downcast node and invoke function on it
		fn(static_cast<GameObject&>(node), gt);
	};
}
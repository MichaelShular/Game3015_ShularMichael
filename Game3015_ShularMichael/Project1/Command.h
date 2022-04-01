#pragma once
#include "Category.h"

#include "../../Common/d3dApp.h"


#include <functional>
#include <cassert>

class sceneNode;
/// This struct is use as a template to create commands 
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
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		fn(static_cast<GameObject&>(node), gt);
	};
}


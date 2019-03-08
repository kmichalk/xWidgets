#pragma once

#include "Component.h"

namespace x::ui
{
	class GridContainer: public Component
	{
		Vector2i _dims;
	public:
		GridContainer();
		~GridContainer();

	};
}


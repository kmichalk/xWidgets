#pragma once

#include "Container.h"

namespace x::ui
{
	class Window;


	class RootComponent: public Container
	{
	protected:
		virtual void onParentUpdated(Component* parent) final override;
	public:
		RootComponent(Window* parentWindow);
		virtual ~RootComponent();
		virtual bool updateLayout() override;
	};
}

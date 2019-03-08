#pragma once

#include "Component.h"


namespace x::ui
{
	class Container: public Component
	{
	protected:
		
		//virtual void updateLayout(Component* triggerComp) override;
	public:
		Container(Window* parentWindow = nullptr);
		virtual ~Container();
		/*virtual void setSize(int width, int height) override;
		virtual void setWidth(int width) override;
		virtual void setHeight(int height) override;*/
	};
}

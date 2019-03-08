#pragma once

//#include "EventData.h"

namespace x
{
	struct MouseEventData;
	struct KeyEventData;
}

namespace x::ui
{
	class Component;

	class InputEventHandler {
		static bool _mousePress(Component* comp, MouseEventData const* data);
		static bool _mouseRelease(Component* comp, MouseEventData const* data);
		static void _keyPress(Component* comp, KeyEventData const* data);
		static void _keyRelease(Component* comp, KeyEventData const* data);
		static void _mouseOver(Component* comp, Vector2i const& mousePos);
		static void _mouseNotOver(Component* comp);
	public:
		static void mouseEvent(Component* comp, MouseEventData const* data);
		static void mouseOver(Component* comp, Vector2i const& mousePos);
		static void keyEvent(Component* comp, KeyEventData const* data);
	};
}

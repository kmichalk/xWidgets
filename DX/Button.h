#pragma once

#include "Component.h"
#include "uiDefaults.h"


namespace x::ui
{
	class Button: public Component
	{
	public:
		struct Style: public Component::Style {
			Color focusColor;
			Color pressedColor;
			Color inactiveColor;
			Color focusBorderColor;
			Color pressedBorderColor;
			Color inactiveBorderColor;
		};

		Color _defaultColor = x::ui::def::ButtonColor;
		Color _focusColor = x::ui::def::ButtonFocusColor;
		Color _pressedColor = x::ui::def::ButtonPressedColor;
		Color _inactiveColor = x::ui::def::ButtonInactiveColor;
		Color _defaultBorderColor = x::ui::def::ButtonBorderColor;
		Color _focusBorderColor = x::ui::def::ButtonFocusBorderColor;
		Color _pressedBorderColor = x::ui::def::ButtonPressedBorderColor;
		Color _inactiveBorderColor = x::ui::def::ButtonInactiveBorderColor;

	protected:
		virtual void onMouseEntered(int x, int y) override;
		virtual void onMouseLeft() override;
		virtual void onMousePressed(MouseEventData const* data) override;
		virtual void onMouseReleased(MouseEventData const* data) override;
	public:
		Event<Button*> Clicked;
		Button();
		virtual ~Button();
		virtual void applyStyle(Component::Style const& style) override;
	};
}

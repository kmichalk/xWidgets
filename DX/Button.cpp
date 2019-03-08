#include "stdafx.h"
#include "Button.h"


void x::ui::Button::onMouseEntered(int x, int y) {
	setColor(_focusColor);
	setBorderColor(_focusBorderColor);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Button::onMouseLeft() {
	setColor(_defaultColor);
	setBorderColor(_defaultBorderColor);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Button::onMousePressed(MouseEventData const * data) {
	setColor(_pressedColor);
	setBorderColor(_pressedBorderColor);
	invoke(Clicked);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Button::onMouseReleased(MouseEventData const * data) {
	if (shape().contains(data->position)) {
		setColor(_focusColor);
		setBorderColor(_focusBorderColor);
	} else {
		setColor(_defaultColor);
		setBorderColor(_defaultBorderColor);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Button::Button():
	_defaultColor(x::ui::def::ButtonColor),
	_focusColor(x::ui::def::ButtonFocusColor),
	_pressedColor(x::ui::def::ButtonPressedColor),
	_inactiveColor(x::ui::def::ButtonInactiveColor),
	_defaultBorderColor(x::ui::def::ButtonBorderColor),
	_focusBorderColor(x::ui::def::ButtonFocusBorderColor),
	_pressedBorderColor(x::ui::def::ButtonPressedBorderColor),
	_inactiveBorderColor(x::ui::def::ButtonInactiveBorderColor)
{
	setColor(_defaultColor);
	setBorderColor(_defaultBorderColor);
	setBorderWidth(x::ui::def::ButtonBorderWidth);
	setSize(x::ui::def::ButtonSize);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Button::~Button() {
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Button::applyStyle(Component::Style const & style) {
	Component::applyStyle(style);
	auto& s = static_cast<Button::Style const&>(style);
	_focusColor = s.focusColor;
	_pressedColor = s.pressedColor;
	_inactiveColor = s.inactiveColor;
	_focusBorderColor = s.focusBorderColor;
	_pressedBorderColor = s.pressedBorderColor;
	_inactiveBorderColor = s.inactiveBorderColor;
	if (!_hidden)
		redraw();
}


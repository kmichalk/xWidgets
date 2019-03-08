#include "stdafx.h"
#include "InputEventHandler.h"
#include "EventData.h"
#include "Component.h"
#include "x/timer.h"


bool x::ui::InputEventHandler::_mousePress(Component * comp, MouseEventData const * data) {
	if (comp->_layout.shape.contains(data->position)) {
		comp->_hasFocus = true;
		bool childInvoked = false;
		for (Component* c : comp->children())
			if (_mousePress(c, data))
				childInvoked = true;
		if (!childInvoked) {
			comp->onMousePressed(data);
			comp->invoke(comp->MousePressed, data);
			return true;
		} else
			return false;
	} else {
		comp->_hasFocus = false;
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::InputEventHandler::_mouseRelease(Component * comp, MouseEventData const * data) {
	if (comp->_layout.shape.contains(data->position)) {
		bool childInvoked = false;
		for (Component* c : comp->children())
			if (_mouseRelease(c, data))
				childInvoked = true;
		if (!childInvoked) {
			comp->onMouseReleased(data);
			comp->invoke(comp->MouseReleased, data);
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::_keyPress(Component * comp, KeyEventData const * data) {
	if (comp->_hasFocus) {
		comp->onKeyPressed(data);
		comp->invoke(comp->KeyPressed, data);
	}
	for (Component* c : comp->children())
		_keyPress(c, data);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::_keyRelease(Component * comp, KeyEventData const * data) {
	if (comp->_hasFocus) {
		comp->onKeyReleased(data);
		comp->invoke(comp->KeyReleased, data);
	}
	for (Component* c : comp->children())
		_keyRelease(c, data);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::_mouseOver(Component * comp, Vector2i const & mousePos) {
	if (!comp->_mouseOver) {
		comp->_mouseOver = true;
		comp->onMouseEntered(mousePos.x, mousePos.y);
		comp->invoke(comp->MouseEntered);
	}
	for (Component* c : comp->children())
		mouseOver(c, mousePos);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::_mouseNotOver(Component * comp) {
	if (comp->_mouseOver) {
		comp->_mouseOver = false;
		comp->onMouseLeft();
		comp->invoke(comp->MouseLeft);
	}
	for (Component* c : comp->children())
		_mouseNotOver(c);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::mouseEvent(Component * comp, MouseEventData const * data) {
	//x::tic();
	if (data->action == Action::Pressed)
		_mousePress(comp, data);
	else
		_mouseRelease(comp, data);

	//std::cout << x::toc() << ": mouseEvent" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::mouseOver(Component * comp, Vector2i const & mousePos) {
	//x::tic();
	if (comp->_layout.shape.contains(mousePos))
		_mouseOver(comp, mousePos);
	else
		_mouseNotOver(comp);
	//std::cout  << x::toc() << ": mouseOver" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::InputEventHandler::keyEvent(Component * comp, KeyEventData const * data) {
	//x::tic();
	if (data->action == Action::Pressed)
		_keyPress(comp, data);
	else
		_keyRelease(comp, data);
	//std::cout << x::toc() << ": keyEvent"<< std::endl;
}

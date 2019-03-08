#include "stdafx.h"
#include "ApplicationComponent.h"

x::ui::ApplicationComponent::ApplicationComponent() {
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::ApplicationComponent::initialize() {
	_initialized = true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::ApplicationComponent::isInitialized() const {
	return _initialized;
}

//void x::ui::ApplicationComponent::draw() const {
//	drawBackground();
//	drawBorder();
//	for (ApplicationComponent* c : children())
//		c->draw();
//}
//
//void x::ui::ApplicationComponent::drawBackground() const {
//	x::gl::setColor(_backgroundColor);
//	glRecti(_position.x, _position.y, _size.x, _size.y);
//}
//
//void x::ui::ApplicationComponent::drawBorder() const {
//	x::gl::setColor(_borderColor);
//	glLineWidth(_borderWidth);
//	int x1 = _position.x + _size.x;
//	int y1 = _position.y + _size.y;
//	int halfBorderWidth = _borderWidth / 2;
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glBegin(GL_LINES);
//	glVertex2i(_position.x, _position.y+ halfBorderWidth);
//	glVertex2i(x1, _position.y + halfBorderWidth);
//	glVertex2i(x1 - halfBorderWidth, _position.y);
//	glVertex2i(x1 - halfBorderWidth, y1);
//	glVertex2i(x1, y1 - halfBorderWidth);
//	glVertex2i(_position.x, y1 - halfBorderWidth);
//	glVertex2i(_position.x + halfBorderWidth, y1);
//	glVertex2i(_position.x + halfBorderWidth, _position.y);
//	glEnd();
//}

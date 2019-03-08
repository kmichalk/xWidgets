#include "stdafx.h"
#include "LayoutProxy.h"
#include "Component.h"


x::ui::LayoutProxy & x::ui::LayoutProxy::operator=(LayoutProxy const & other) {
	_comp->_layout = other._comp->_layout;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::setAnchor(Anchor const & anchor) {
	_layout->properties.anchor = anchor;
	_comp->updateLayout();
	_comp->redraw();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::setAnchor(Side side, int distance) {
	_layout->properties.anchor.set(side, distance);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::unsetAnchor(Side side) {
	_layout->properties.anchor.unset(side);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::unsetAnchor() {
	_layout->properties.anchor.unset();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::applyAnchorInCurrentBounds(Anchor::Mode mode) {
	auto& parentShape = _comp->parent()->shape();
	_layout->properties.anchor.left = _layout->shape.position.x - parentShape.position.x;
	_layout->properties.anchor.right = parentShape.size.x - _layout->shape.position.x - _layout->shape.size.x;
	_layout->properties.anchor.top = _layout->shape.position.y - parentShape.position.y;
	_layout->properties.anchor.bottom = parentShape.size.y - _layout->shape.position.y - _layout->shape.size.y;
	_layout->properties.anchor.setAllModes(mode);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::setMinSize(Vector2i const & size) {
	_layout->properties.sizeMin = size;
	_comp->updateLayout();
	_comp->redraw();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::LayoutProxy::setMaxSize(Vector2i const & size) {
	_layout->properties.sizeMax = size;
	_comp->updateLayout();
	_comp->redraw();
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rect x::ui::LayoutProxy::bounds() const {
	return Rect();
}


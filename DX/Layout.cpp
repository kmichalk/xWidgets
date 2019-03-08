#include "stdafx.h"
#include "Layout.h"


x::ui::Layout::Layout(Component * comp):
	_comp(comp),
	locked(false)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Layout::Layout(Component* comp, Rectangle const & shape, LayoutProperties const & properties):
	shape(shape),
	properties(properties),
	locked(false) {
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::Layout::update(Layout & parent) {
	bool result = false;
	if (shape.size.x < properties.sizeMin.x) {
		shape.size.x = properties.sizeMin.x;
		if (shape.size.y < properties.sizeMin.y)
			shape.size.y = properties.sizeMin.y;
		result = true;
	} else if (shape.size.y < properties.sizeMin.y) {
		shape.size.y = properties.sizeMin.y;
		result = true;
	}

	int prevValue;
	if (properties.anchor.leftEnabled()) {
		prevValue = shape.position.x;
		shape.position.x = parent.shape.position.x + properties.anchor.left;
		if (prevValue != shape.position.x)
			result = true;
		if (properties.anchor.rightEnabled()) {
			prevValue = shape.size.x;
			shape.size.x = x::max(parent.shape.size.x - shape.position.x + parent.shape.position.x - properties.anchor.right, properties.sizeMin.x);
			if (prevValue != shape.size.x) {
				result = true;
				//parent.shape.stretchWidth(shape.size.x + properties.anchor.left + properties.anchor.right);
			}
		}
	} else if (properties.anchor.rightEnabled()) {
		prevValue = shape.position.x;
		shape.position.x = parent.shape.position.x + parent.shape.size.x - shape.size.x - properties.anchor.right;
		if (prevValue != shape.position.x)
			result = true;
	}

	if (properties.anchor.topEnabled()) {
		prevValue = shape.position.y;
		shape.position.y = parent.shape.position.y + properties.anchor.top;
		if (prevValue != shape.position.y)
			result = true;
		if (properties.anchor.bottomEnabled()) {
			prevValue = shape.size.y;
			shape.size.y = x::max(parent.shape.size.y - shape.position.y + parent.shape.position.y - properties.anchor.bottom, properties.sizeMin.y);
			if (prevValue != shape.position.y) {
				result = true;
				//parent.shape.stretchHeight(shape.size.y + properties.anchor.top + properties.anchor.bottom);
			}
		}
	} else if (properties.anchor.bottomEnabled()) {
		prevValue = shape.position.y;
		shape.position.y = parent.shape.position.y + parent.shape.size.y - shape.size.y - properties.anchor.bottom;
		if (prevValue != shape.position.y)
			result = true;
	}
	return result;

}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Vector2i x::ui::Layout::trimmedSize(Vector2i const & size) const {
	return Vector2i(
		x::trim(size.x, properties.sizeMin.x, properties.sizeMax.x),
		x::trim(size.y, properties.sizeMin.y, properties.sizeMax.y)
	);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rect x::ui::Layout::bounds() const {
	return Rect(
		shape.size.x + properties.anchor.left + properties.anchor.right,
		shape.size.y + properties.anchor.top + properties.anchor.bottom,
		shape.position.x - properties.anchor.left,
		shape.position.y - properties.anchor.top
	);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Vector2i x::ui::Layout::boundSize() const {
	return Vector2i(
		shape.size.x + properties.anchor.left + properties.anchor.right,
		shape.size.y + properties.anchor.top + properties.anchor.bottom
	);
	/*return Vector2i(
		properties.anchor.horizontalEnabled() ?
			(shape.size.x
				+ (properties.anchor.leftMode == Anchor::Mode::Pixel ? properties.anchor.left : 0)
				+ (properties.anchor.rightMode == Anchor::Mode::Pixel ? properties.anchor.right : 0))
			: 0,
		properties.anchor.verticalEnabled() ?
			(shape.size.y
				+ (properties.anchor.topMode == Anchor::Mode::Pixel ? properties.anchor.top : 0)
				+ (properties.anchor.bottomMode == Anchor::Mode::Pixel ? properties.anchor.bottom : 0))
			: 0
	);*/
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Vector2i x::ui::Layout::boundPosition() const {
	return Vector2i(
		shape.position.x - properties.anchor.left,
		shape.position.y - properties.anchor.top
	);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Layout::applyAnchorInCurrentBounds(Anchor::Mode mode) {
	auto& parentShape = shape;
	properties.anchor.left = shape.position.x - parentShape.position.x;
	properties.anchor.right = parentShape.position.x - shape.position.x - shape.size.x;
	properties.anchor.top = shape.position.y - parentShape.position.y;
	properties.anchor.bottom = parentShape.position.y - shape.position.y - shape.size.y;
	properties.anchor.setAllModes(mode);
}

#include "stdafx.h"
#include "Rect.h"


bool x::Rect::contains(int x, int y) const {
	return
		x >= position.x &&
		y >= position.y &&
		x <= position.x + size.x &&
		y <= position.y + size.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::Rect::contains(Vector2i const & p) const {
	return
		p.x >= position.x &&
		p.y >= position.y &&
		p.x <= position.x + size.x &&
		p.y <= position.y + size.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::Rect::intersects(Rect const & other) const {
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rect::Borders x::Rect::borders() const {
	return Borders{
		leftBorder(),
		rightBorder(),
		topBorder(),
		bottomBorder()
	};
}

///////////////////////////////////////////////////////////////////////////////////////////////

//void x::Rect::fit(Rect const & other) {
//}

void x::Rect::fit(Vector2i const & maxSize) {
	if (size.x > maxSize.x)
		size.x = maxSize.x;
	if (size.y > maxSize.y)
		size.y = maxSize.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::Rect::fitWidth(int maxWidth) {
	if (size.x > maxWidth)
		size.x = maxWidth;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::Rect::fitHeight(int maxHeight) {
	if (size.y > maxHeight)
		size.y = maxHeight;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::Rect::stretchWidth(int minWidth) {
	if (size.x < minWidth)
		size.x = minWidth;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::Rect::stretchHeight(int minHeight) {
	if (size.y < minHeight)
		size.y = minHeight;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::Rect::stretch(Vector2i const & minSize) {
	if (size.x < minSize.x)
		size.x = minSize.x;
	if (size.y < minSize.y)
		size.y = minSize.y;
}

//void x::Rect::stretch(Rect const & other) {
//	//if (size.x < )
//	/*auto rectBorders = other.borders();
//	auto borders = this->borders();
//	if (borders.right > rectBorders.right)
//		size.x = rectBorders.right - x::min(position.x, other.position.x);
//	if (borders.bottom > rectBorders.bottom)
//		size.y = rectBorders.bottom - x::min(position.y, other.position.y);*/
//}
//
//void x::Rect::stretch(Rect const & other, Vector2i const & sizeMax) {
//	auto rectBorders = other.borders();
//	auto borders = this->borders();
//	if (borders.right < rectBorders.right)
//		size.x = x::min(rectBorders.right - position.x, sizeMax.x);
//	if (borders.bottom < rectBorders.bottom)
//		size.y = x::min(rectBorders.bottom - position.y, sizeMax.y);
//}

#include "stdafx.h"
#include "Rectangle.h"


x::Rectangle::Rectangle():
	Rect(),
	color(),
	borderColor(),
	borderWidth(0)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rectangle::Rectangle(int xSize, int ySize, int xPos, int yPos, Color const & color):
	Rect(xSize, ySize, xPos, yPos),
	color(color),
	borderColor(),
	borderWidth(0)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rectangle::Rectangle(int xSize, int ySize, int xPos, int yPos, Color const & color, Color const & borderColor, int borderWidth):
	Rect(xSize, ySize, xPos, yPos),
	color(color),
	borderColor(borderColor),
	borderWidth(borderWidth) 
{
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rectangle::Rectangle(Vector2i const& size, Vector2i const& position, Color const & color):
	Rect(size, position),
	color(color),
	borderColor(),
	borderWidth(0) {
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rectangle::Rectangle(Vector2i const& size, Vector2i const& position, Color const & color, Color const & borderColor, int borderWidth):
	Rect(size, position),
	color(color),
	borderColor(borderColor),
	borderWidth(borderWidth) {
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::Rectangle::draw() const {
	if (borderWidth > 0) {
		x::gl::setColor(borderColor);
		glRecti(
			position.x, 
			position.y, 
			position.x + size.x, 
			position.y + size.y);
		int x0 = position.x + borderWidth;
		int y0 = position.y + borderWidth;
		int x1 = position.x + size.x - borderWidth;
		int y1 = position.y + size.y - borderWidth;
		if (x0 < x1 && y0 < y1) {
			x::gl::setColor(color);
			glRecti(x0, y0, x1, y1);
		}
	} else {
		x::gl::setColor(color);
		glRecti(
			position.x,
			position.y,
			position.x + size.x,
			position.y + size.y);
	}
}

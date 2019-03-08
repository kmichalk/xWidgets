#pragma once

#include "Rect.h"

namespace x
{
	class Rectangle: public Rect
	{
	public:
		Color color;
		Color borderColor;
		int borderWidth;

		Rectangle();
		Rectangle(int xSize, int ySize, int xPos, int yPos, Color const& color = Colors::White);
		Rectangle(int xSize, int ySize, int xPos, int yPos, Color const& color, Color const& borderColor, int borderWidth = 1);
		Rectangle(Vector2i const& size, Vector2i const& position, Color const& color = Colors::White);
		Rectangle(Vector2i const& size, Vector2i const& position, Color const& color, Color const& borderColor, int borderWidth = 1);
		Rectangle(Rectangle const&) = default;
		Rectangle(Rectangle&&) = default;
		Rectangle& operator=(Rectangle const&) = default;
		Rectangle& operator=(Rectangle &&) = default;
		using Rect::operator=;
		void draw() const;
	};
}

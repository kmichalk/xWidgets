#pragma once

#include "Movable.h"


namespace x::ui
{
	class Geometric: public Movable
	{
	public:
		virtual ~Geometric() = default;
		virtual void setSize(int width, int height) = 0;
		virtual void setSize(Vector2i const& size);
		virtual Vector2i position() const = 0;
		virtual void setWidth(int width) = 0;
		virtual unsigned width() const = 0;
		virtual void setHeight(int height) = 0;
		virtual unsigned height() const = 0;
		virtual Vector2i size() const = 0;
		/*virtual Vector2i topLeftCorner() const = 0;
		virtual Vector2i topRightCorner() const = 0;
		virtual Vector2i bottomLeftCorner() const = 0;
		virtual Vector2i bottomRightCorner() const = 0;
		virtual int topBorder() const = 0;
		virtual int bottomBorder() const = 0;
		virtual int leftBorder() const = 0;
		virtual int rightBorder() const = 0;*/
	};

	
	inline void Geometric::setSize(Vector2i const& size) {
		setSize(size.x, size.y);
	}
}


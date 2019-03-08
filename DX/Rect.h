#pragma once

namespace x
{
	class Rect
	{
	public:
		struct Borders {
			int left;
			int right;
			int top;
			int bottom;
		};

		Vector2i size;
		Vector2i position;

		Rect() = default;
		Rect(int xSize, int ySize, int xPos = 0, int yPos = 0);
		Rect(Vector2i const& size, Vector2i const& position = {0, 0});
		Rect(Rect const&) = default;
		Rect(Rect&&) = default;
		Rect& operator=(Rect const&) = default;
		Rect& operator=(Rect&&) = default;
		bool contains(int x, int y) const;
		bool contains(Vector2i const& p) const;
		bool intersects(Rect const& other) const;
		Vector2i topLeftCorner() const;
		Vector2i topRightCorner() const;
		Vector2i bottomLeftCorner() const;
		Vector2i bottomRightCorner() const;
		int topBorder() const;
		int bottomBorder() const;
		int leftBorder() const;
		int rightBorder() const;
		Borders borders() const;
		//void fit(Rect const& other);
		void fit(Vector2i const& maxSize);
		void fitWidth(int maxWidth);
		void fitHeight(int maxHeight);
		void stretchWidth(int minWidth);
		void stretchHeight(int minHeight);
		void stretch(Vector2i const& minSize);
		int field() const;
		//void stretch(Rect const& other);
		//void stretch(Rect const& other, Vector2i const& sizeMax);
	};
}


inline x::Rect::Rect(int xSize, int ySize, int xPos, int yPos):
	size(xSize, ySize),
	position(xPos, yPos)
{
}

inline x::Rect::Rect(Vector2i const & size, Vector2i const & position):
	size(size),
	position(position)
{
}

inline x::Vector2i x::Rect::topLeftCorner() const {
	return position;
}

inline x::Vector2i x::Rect::topRightCorner() const {
	return {position.x + size.x, position.y};
}

inline x::Vector2i x::Rect::bottomLeftCorner() const {
	return {position.x, position.y + size.y};
}

inline x::Vector2i x::Rect::bottomRightCorner() const {
	return {position.x + size.x, position.y + size.y};
}

inline int x::Rect::topBorder() const {
	return position.y;
}

inline int x::Rect::bottomBorder() const {
	return position.y + size.y;
}

inline int x::Rect::leftBorder() const {
	return position.x;
}

inline int x::Rect::rightBorder() const {
	return position.x + size.x;
}

inline int x::Rect::field() const {
	return size.x * size.y;
}
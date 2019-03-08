#pragma once

namespace x::ui
{
	class Movable
	{
	public:
		virtual ~Movable() = default;
		virtual void move(int x, int y) = 0;
		virtual void setPosition(int x, int y) = 0;
		void move(Vector2i const& offset);
		void setPosition(Vector2i const& pos);
	};


	inline void Movable::move(Vector2i const& offset) {
		move(offset.x, offset.y);
	}

	inline void Movable::setPosition(Vector2i const& pos) {
		setPosition(pos.x, pos.y);
	}

}

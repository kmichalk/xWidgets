#pragma once

namespace x::ui
{
	class Drawable
	{
	public:
		virtual void draw() const = 0;
		virtual ~Drawable() = default;
	};
}

#pragma once

#include "Rectangle.h"
#include "LayoutProperties.h"


namespace x::ui
{
	class Component;

	class Layout
	{
		Component* _comp;
	public:
		Rectangle shape;
		LayoutProperties properties;
		bool locked;

		Layout(Component* comp);
		Layout(Component* comp, Rectangle const& shape, LayoutProperties const& properties);
		Layout(Layout const&) = default;
		Layout(Layout&&) = default;
		Layout& operator=(Layout const&) = default;
		Layout& operator=(Layout&&) = default;
		bool update(Layout& parent);
		Vector2i trimmedSize(Vector2i const& size) const;
		Rect bounds() const;
		Vector2i boundSize() const;
		Vector2i boundPosition() const;
		void applyAnchorInCurrentBounds(Anchor::Mode mode = Anchor::Mode::Pixel);
		void lock();
		void unlock();
	};
}

__forceinline void x::ui::Layout::lock() {
	locked = true;
}

__forceinline void x::ui::Layout::unlock() {
	locked = false;
}

#pragma once

#include "LayoutProperties.h"

namespace x::ui
{
	class Component;
	class Layout;

	class LayoutProxy
	{
		Component* _comp;
		Layout* _layout;
	public:
		/*using Component::setAnchor;
		using Component::unsetAnchor;
		using Component::applyAnchorInCurrentBounds;*/

		__forceinline LayoutProxy(Component* comp, Layout* layout) noexcept:
			_comp(comp),
			_layout(layout)
		{ }

		LayoutProxy& operator=(LayoutProxy const& other);
		void setAnchor(Anchor const& anchor);
		void setAnchor(Side side, int distance);
		void unsetAnchor(Side side);
		void unsetAnchor();
		void applyAnchorInCurrentBounds(Anchor::Mode mode = Anchor::Mode::Pixel);
		void setMinSize(Vector2i const& size);
		void setMaxSize(Vector2i const& size);
		Rect bounds() const;
	};
}

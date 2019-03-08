#pragma once

#include "_Component.h"
#include "Geometric.h"
#include "Drawable.h"
#include "ComponentCollection.h"
#include "EventData.h"
#include "Layout.h"
#include "LayoutProxy.h"

namespace x::ui
{
	class Window;

	class Component: public _Component<Component>, public Geometric, public Drawable
	{
	protected:
		/*struct Anchor {
			static constexpr int UNSET = std::numeric_limits<int>::min();
			int left = UNSET;
			int right = UNSET;
			int top = UNSET;
			int bottom = UNSET;
		};*/

	public:
		struct Style {
			Color color;
			Color borderColor;
			unsigned borderWidth;
		};

		friend class InputEventHandler;
		friend class LayoutProxy;

	private:
		Window* _parentWindow;

		//virtual bool _processAnchor();
		//bool _processSizeLimits();
		//bool _processLayout(Rect& parentMinRect);

	protected:
		bool _hidden;
		bool _valid;
		bool _active;
		bool _initialized;
		bool _mouseOver;
		bool _hasFocus;
		std::string _name;
		Layout _layout;

		Component(Window* parentWindow = nullptr);
		using _Component<Component>::children;
		virtual void onParentUpdated(Component* parent) override;
		//virtual void updateLayout(Component* triggerComp);
		bool updateLayoutImpl(Layout& parentLayout);
		bool updateLayoutImpl();
		template<class _Comp, class... _Arg>
		void invoke(Event<_Comp*, _Arg...> const& event, _Arg... args);
		template<class _Comp, class... _Arg>
		void updateAndInvoke(Event<_Comp*, _Arg...> const& event, _Arg... args);
		template<class _Comp, class... _Arg>
		void invalidateAndInvoke(Event<_Comp*, _Arg...> const& event, _Arg... args);
		virtual void onMouseEntered(int x, int y);
		virtual void onMouseLeft();
		virtual void onMousePressed(MouseEventData const* data);
		virtual void onMouseReleased(MouseEventData const* data);
		virtual void onKeyPressed(KeyEventData const* data);
		virtual void onKeyReleased(KeyEventData const* data);
	public:
		Event<Component*> Moved;
		Event<Component*> Shown;
		Event<Component*> Hidden;
		Event<Component*> Resized;
		Event<Component*> ColorChanged;
		Event<Component*> BorderColorChanged;
		Event<Component*> BorderWidthChanged;
		Event<Component*> NameChanged;
		MouseEvent<Component*> MousePressed;
		MouseEvent<Component*> MouseReleased;
		Event<Component*> MouseEntered;
		Event<Component*> MouseLeft;
		KeyEvent<Component*> KeyPressed;
		KeyEvent<Component*> KeyReleased;
		Component(Component const& other) = default;
		Component(Component&&) = delete;
		virtual ~Component();
		virtual bool updateLayout();
		virtual Component* copy() const override;
		ComponentCollection components() const;
		using Geometric::setSize;
		using Movable::move;
		using Movable::setPosition;
		virtual void setSize(int width, int height) override;
		virtual Vector2i size() const override;
		virtual void move(int x, int y) override;
		virtual void setPosition(int x, int y) override;
		virtual Vector2i position() const override;
		virtual void setWidth(int width) override;
		virtual unsigned width() const override;
		virtual void setHeight(int height) override;
		virtual unsigned height() const override;
		void setColor(Color const& color);
		Color color() const;
		void setBorderColor(Color const& color);
		Color borderColor() const;
		void setBorderWidth(unsigned width);
		unsigned borderWidth() const;
		virtual void draw() const override;
		/*virtual Vector2i topLeftCorner() const override;
		virtual Vector2i topRightCorner() const override;
		virtual Vector2i bottomLeftCorner() const override;
		virtual Vector2i bottomRightCorner() const override;
		virtual int topBorder() const override;
		virtual int bottomBorder() const override;
		virtual int leftBorder() const override;
		virtual int rightBorder() const override;*/
		Window* parentWindow() const;
		Rectangle const& shape() const;
		void invalidate();
		bool upToDate() const;
		bool initialized() const;
		void hide();
		void show();
		void refresh();
		void redraw();
		bool hidden() const;
		void setName(std::string const& name);
		std::string const& name() const;
		void suspend();
		void resume();
		bool suspended() const;
		void setAnchor(Anchor const& anchor);
		void setAnchor(Side side, int distance, Anchor::Mode mode = Anchor::Mode::Pixel);
		void unsetAnchor(Side side);
		void unsetAnchor();
		LayoutProxy layout();
		virtual void applyStyle(Style const& style);
		void fit(Rect const& rect);
		void stretch(Rect const& rect);
		void lockSize();
	};

	
}

__forceinline x::ui::ComponentCollection x::ui::Component::components() const {
	return ComponentCollection(children());
}


template<class _Comp, class ..._Arg>
__forceinline void x::ui::Component::invoke(x::core::Event<_Comp*, _Arg...> const & event, _Arg ...args) {
	if (event && _active)
		event(static_cast<_Comp*>(this), (_Arg&&)args...);
}

template<class _Comp, class ..._Arg>
inline void x::ui::Component::updateAndInvoke(x::core::Event<_Comp*, _Arg...> const & event, _Arg ...args) {
	if (_active) {
		parentWindow()->updateLayout();
		invalidate();
		if (event)
			event(static_cast<_Comp*>(this), (_Arg&&)args...);
	}
}

template<class _Comp, class ..._Arg>
inline void x::ui::Component::invalidateAndInvoke(x::core::Event<_Comp*, _Arg...> const & event, _Arg ...args) {
	if (_active) {
		invalidate();
		if (event)
			event(static_cast<_Comp*>(this), (_Arg&&)args...);
	}
}

inline x::ui::Window * x::ui::Component::parentWindow() const {
	return _parentWindow;
}

inline x::Rectangle const & x::ui::Component::shape() const {
	return _layout.shape;
}

__forceinline x::ui::LayoutProxy x::ui::Component::layout() {
	return LayoutProxy(this, &_layout);
}
#pragma once

#include "ApplicationComponent.h"
#include "RootComponent.h"

namespace x::ui
{
	class Window: public ApplicationComponent
	{
		static constexpr int _MAX_SIZE_X = std::numeric_limits<int>::max();
		static constexpr int _MAX_SIZE_Y = std::numeric_limits<int>::max();

		Color _clearColor;
		Rect _rect;
		Rect _clientRect;
		std::string _title;
		GLFWwindow* _glfwWindow;
		RootComponent* _root;
		bool _hidden;
		bool _opened;
		mutable bool _upToDate;
		Vector2i _lastMousePosition;
		bool _ignoreLayoutSize;

		static void _keyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods);
		static void _mouseButtonCallback(GLFWwindow* glfwWindow, int button, int action, int mods);
		static void _windowSizeCallback(GLFWwindow* glfwWindow, int width, int height);
		static void _windowRefreshCallback(GLFWwindow* glfwWindow);
		static void _cursorPosCallback(GLFWwindow* glfwWindow, double x, double y);
		static void _closeCallback(GLFWwindow* glfwWindow);
		static void _setupCallbacks(GLFWwindow* glfwWindow);
		void _setupView() const;
		void _setSize(int width, int height);
		void _setGLFWSize(int width, int height);
		void _updateSize();
		void _close();
	protected:
		static Window* fromGLFW(GLFWwindow* window);
	public:
		Event<Window*> Closing;
		//Event<Window*> Closed;
		KeyEvent<Window*> KeyPressed;
		KeyEvent<Window*> KeyReleased;

		Window(Vector2i const& size, std::string const& title);
		virtual ~Window();
		virtual void initialize() override;
		void setSize(int width, int height);
		void setSize(Vector2i const& size);
		Vector2i size() const;
		void move(int x, int y);
		void move(Vector2i const& offset);
		void setPosition(int x, int y);
		void setPosition(Vector2i const& pos);
		Vector2i position() const;
		void setWidth(int width);
		unsigned width() const;
		void setHeight(int height);
		unsigned height() const;
		void setClearColor(Color const& color);
		Color clearColor() const;
		Rect rect() const;
		Component* root() const;
		void open();
		void close();
		bool opened();
		void redraw() const;
		void clear();
		void invalidate();
		void refresh();
		void stretch();
		void updateLayout();
		Vector2i mousePosition() const;
		void setIgnoreLayoutSize(bool value);
	};
}


__forceinline x::ui::Window* x::ui::Window::fromGLFW(GLFWwindow* window) {
	return static_cast<Window*>(glfwGetWindowUserPointer(window));
}

inline void x::ui::Window::setSize(Vector2i const& size) {
	setSize(size.x, size.y);
}

inline void x::ui::Window::move(Vector2i const& offset) {
	move(offset.x, offset.y);
}

inline void x::ui::Window::setPosition(Vector2i const& pos) {
	setPosition(pos.x, pos.y);
}
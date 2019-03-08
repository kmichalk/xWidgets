#include "stdafx.h"
#include "Window.h"
#include "Application.h"
#include "InputEventHandler.h"
#include "uiDefaults.h"


void x::ui::Window::_keyCallback(GLFWwindow * glfwWindow, int key, int scancode, int action, int mods) {
	KeyEventData data{(Key)key, (Action)action, mods};
	Window* window = fromGLFW(glfwWindow);
	InputEventHandler::keyEvent(window->_root, &data);
	if (data.action == Action::Pressed) {
		if (window->KeyPressed)
			window->KeyPressed(window, &data);
	} else {
		if (window->KeyReleased)
			window->KeyReleased(window, &data);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_mouseButtonCallback(GLFWwindow * glfwWindow, int button, int action, int mods) {
	MouseEventData data{(Button)button, (Action)action, mods};
	double x, y;
	glfwGetCursorPos(glfwWindow, &x, &y);
	data.position.x = (int)x;
	data.position.y = (int)y;
	InputEventHandler::mouseEvent(fromGLFW(glfwWindow)->_root, &data);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_windowSizeCallback(GLFWwindow * glfwWindow, int width, int height) {
	fromGLFW(glfwWindow)->setSize(width, height);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_windowRefreshCallback(GLFWwindow * glfwWindow) {
	auto window = fromGLFW(glfwWindow);
	window->redraw();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_cursorPosCallback(GLFWwindow * glfwWindow, double x, double y) {
	Window* window = fromGLFW(glfwWindow);
	window->_lastMousePosition.x = (int)x;
	window->_lastMousePosition.y = (int)y;
	InputEventHandler::mouseOver(window->_root, {(int)x, (int)y});
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_closeCallback(GLFWwindow * glfwWindow) {
	Window* window = fromGLFW(glfwWindow);
	Application* app = static_cast<Application*>(window->parent()); 
	window->_close();
	app->removeComponent(window);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_setupView() const {
	glLoadIdentity();
	glScalef(1.0f, -1.0f, 1.0f);
	glViewport(0, 0, _rect.size.x, _rect.size.y);
	glOrtho(0, _rect.size.x, 0, _rect.size.y, -1, 1);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_setSize(int width, int height) {
	_root->setSize(width, height);
	if (_ignoreLayoutSize)
		_rect.size = {width, height};
	else
		_rect = _root->shape();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_setGLFWSize(int width, int height) {
	glfwSetWindowSize(_glfwWindow, width, height);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_updateSize() {
	_rect = _root->shape();
	_setGLFWSize(_rect.size.x, _rect.size.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_close() {
	Closing(this);
	_opened = false;
	_hidden = false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::_setupCallbacks(GLFWwindow * glfwWindow) {
	glfwSetKeyCallback(glfwWindow, _keyCallback);
	glfwSetMouseButtonCallback(glfwWindow, _mouseButtonCallback);
	glfwSetFramebufferSizeCallback(glfwWindow, _windowSizeCallback);
	glfwSetWindowRefreshCallback(glfwWindow, _windowRefreshCallback);
	glfwSetCursorPosCallback(glfwWindow, _cursorPosCallback);
	glfwSetWindowCloseCallback(glfwWindow, _closeCallback);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::redraw() const {
	//glfwMakeContextCurrent(_glfwWindow);
	_setupView();
	const_cast<Window*>(this)->clear();
	_root->draw();
	glfwSwapBuffers(_glfwWindow);
	_upToDate = true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::initialize() {
	_root = new RootComponent(this);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Window::Window(Vector2i const& size, std::string const & title):
	_clearColor(def::WindowClearColor),
	_rect(size),
	_clientRect(),
	_title(title),
	_glfwWindow(nullptr),
	_root(nullptr),
	_hidden(false),
	_opened(false),
	_upToDate(false),
	_ignoreLayoutSize(false)
{
	SetType;
	_glfwWindow = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
	//glfwGetWindowPos(_glfwWindow, &_rect.position.x, &_rect.position.y);
	if (_glfwWindow == nullptr) {
		_initialized = false;
	}
	glfwSetWindowUserPointer(_glfwWindow, this);
	glfwMakeContextCurrent(_glfwWindow);
	glfwSwapInterval(1);
	glMatrixMode(GL_PROJECTION);

	glfwGetWindowPos(_glfwWindow, &_clientRect.position.x, &_clientRect.position.y);
	glfwGetWindowSize(_glfwWindow, &_clientRect.size.x, &_clientRect.size.y);
	//glLoadIdentity();
	//glOrtho(0.0, (double)_rect.size.x, 0.0, (double)_rect.size.y, -1.0, 1.0);
	//glMatrixMode(GL_MODELVIEW);
	
	//glViewport(0, 0, _rect.size.x, _rect.size.y);
	//glfwGetFramebufferSize(_glfwWindow, (int*)&_width, (int*)&_height);
	_setupCallbacks(_glfwWindow);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Window::~Window() {
	close();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::setSize(int width, int height) {
	_setSize(width, height);
	glfwSetWindowSize(_glfwWindow, _rect.size.x, _rect.size.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Vector2i x::ui::Window::size() const {
	return _rect.size;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::move(int x, int y) {
	_rect.position.x += x;
	_rect.position.y += y;
	glfwSetWindowPos(_glfwWindow, _rect.position.x, _rect.position.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::setPosition(int x, int y) {
	_rect.position.x = x;
	_rect.position.y = y;
	glfwSetWindowPos(_glfwWindow, _rect.position.x, _rect.position.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Vector2i x::ui::Window::position() const {
	return _rect.position;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::setWidth(int width) {
	_rect.size.x = width;
	glfwSetWindowSize(_glfwWindow, _rect.size.x, _rect.size.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

unsigned x::ui::Window::width() const {
	return _rect.size.x;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::setHeight(int height) {
	_rect.size.y = height;
	glfwSetWindowSize(_glfwWindow, _rect.size.x, _rect.size.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

unsigned x::ui::Window::height() const {
	return _rect.size.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::setClearColor(Color const & color) {
	_clearColor = color;
	x::gl::setClearColor(color);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Color x::ui::Window::clearColor() const {
	return _clearColor;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Rect x::ui::Window::rect() const {
	return _rect;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Component * x::ui::Window::root() const {
	return _root;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::open() {
	_opened = true;
	_hidden = false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::close() {
	Closing(this);
	_opened = false;
	_hidden = false;
	glfwSetWindowShouldClose(_glfwWindow, true);
	//glfwDestroyWindow(_glfwWindow);
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::Window::opened() {
	/*if (glfwWindowShouldClose(_glfwWindow))
		close();*/
	return _opened;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::invalidate() {
	_upToDate = false;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::refresh() {
	if (!_upToDate)
		redraw();
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::stretch() {
	_rect = _root->shape();
	_setGLFWSize(_rect.size.x, _rect.size.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::updateLayout() {
	if (_root != nullptr) {
		_root->updateLayout();
		if (!_ignoreLayoutSize)
			_updateSize();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::Vector2i x::ui::Window::mousePosition() const {
	return _lastMousePosition;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Window::setIgnoreLayoutSize(bool value) {
	_ignoreLayoutSize = value;
}

//void x::ui::Window::setSize(Vector2u const & size) {
//	ApplicationComponent::setSize(size);
//
//}

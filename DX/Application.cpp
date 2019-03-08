#include "stdafx.h"
#include "Application.h"
#include "Window.h"


//void x::ui::Application::initialize() {
//	ApplicationComponent::initialize();
//}

void x::ui::Application::errorCallback(int error, char const * description) {
	std::cout << description << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Application::Application(int argCount, char ** args):
	_args(args, args + argCount),
	_commandLine(),
	_fullPath(_args[0]),
	_name(_fullPath.substr(_fullPath.find_last_of((char)std::filesystem::path::preferred_separator) + 1)),
	_mainWindow(nullptr),
	_initialized(false)
{
	SetType;	
	if (_initialized = glfwInit()) {
		glfwSetErrorCallback(errorCallback);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glLoadIdentity();
		glScalef(1.0f, -1.0f, 1.0f);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Application::~Application() {
	glfwTerminate();
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::Application::start(Window* mainWindow) {
	if (!_initialized || mainWindow == nullptr)
		return false;
	addComponent(mainWindow);
	_mainWindow = mainWindow;
	_mainWindow->open();
	_mainWindow->root()->updateLayout();
	_mainWindow->stretch();
	run();
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::Application::start(Vector2i const & windowSize, std::string const & windowName, Component * mainComponent) {
	if (!_initialized)
		return false;
	_mainWindow = new Window(windowSize, windowName);
	_mainWindow->initialize();
	_mainWindow->root()->addComponent(mainComponent);
	_mainWindow->open();
	_mainWindow->root()->updateLayout();
	run();
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::string const & x::ui::Application::commandLine() const {
	return _commandLine;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::string const & x::ui::Application::name() const {
	return _name;
}

///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> const & x::ui::Application::commandLineArgs() const {
	return _args;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::vector<x::ui::Window*> x::ui::Application::windows() const {
	return children()
		.copy_if(
			[](ApplicationComponent* c) {
				return c->type() == Type::of<Window>(); 
			})
		.reinterpret<Window*>();
}

x::ui::Window * x::ui::Application::mainWindow() const {
	return _mainWindow;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Application::run() {
	while (_mainWindow->opened()) {		
		process();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

void x::ui::Application::process() {
	glfwWaitEvents();
	_mainWindow->refresh();
	//_mainWindow->invalidate();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

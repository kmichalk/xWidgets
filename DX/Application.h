#pragma once

#include "Window.h"

namespace x::ui
{
	class Window;

	class Application: public ApplicationComponent
	{
		std::vector<std::string> _args;
		std::string _commandLine;
		std::string _fullPath;
		std::string _name;
		Window* _mainWindow;
		bool _initialized;

		static void errorCallback(int error, char const* description);

	protected:
		virtual void run();
		virtual void process();

	public:
		Application(int argCount, char** args);
		virtual ~Application();
		bool start(Window* mainWindow);
		bool start(Vector2i const& windowSize, std::string const& windowName, Component* mainComponent);
		std::string const& commandLine() const;
		std::string const& name() const;
		std::vector<std::string> const& commandLineArgs() const;
		x::vector<Window*> windows() const;
		Window* mainWindow() const;
	};
}

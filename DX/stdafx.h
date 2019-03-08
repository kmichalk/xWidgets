#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <chrono>
#include <thread>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

#include "x/vector.h"

#include "Vector2.h"
#include "Color.h"
#include "Type.h"
#include "glUtil.h"
#include "Event.h"
#include "Rectangle.h"
#include "types.h"

namespace x::ui
{
	using namespace x::core;
}
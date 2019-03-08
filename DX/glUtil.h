#pragma once

namespace x::gl
{
	__forceinline void setColor(x::Color3b const& color) {
		glColor3ub(color.r, color.g, color.b);
	}

	__forceinline void setColor(x::Color3i const& color) {
		glColor3i(color.r, color.g, color.b);
	}

	__forceinline void setColor(x::Color3f const& color) {
		glColor3f(color.r, color.g, color.b);
	}

	__forceinline void setColor(x::Color3d const& color) {
		glColor3d(color.r, color.g, color.b);
	}

	__forceinline void setColor(x::Color4b const& color) {
		glColor4ub(color.r, color.g, color.b, color.a);
	}

	__forceinline void setColor(x::Color4i const& color) {
		glColor4i(color.r, color.g, color.b, color.a);
	}

	__forceinline void setColor(x::Color4f const& color) {
		glColor4f(color.r, color.g, color.b, color.a);
	}

	__forceinline void setColor(x::Color4d const& color) {
		glColor4d(color.r, color.g, color.b, color.a);
	}

	__forceinline void setClearColor(x::Color const& color) {
		glClearColor(color.r, color.g, color.b, color.a);
	}
}
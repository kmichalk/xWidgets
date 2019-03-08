#pragma once

namespace x::ui::def
{
	static constexpr x::Color WindowClearColor = {0, 0, 0};

	static constexpr x::Color ComponentColor = {40, 40, 40};
	static constexpr x::Color ComponentBorderColor = {55, 55, 55};
	static constexpr unsigned ComponentBorderWidth = 3;

	static constexpr x::Color ButtonColor = {60, 60, 60};
	static constexpr x::Color ButtonFocusColor = {55, 55, 55};
	static constexpr x::Color ButtonPressedColor = {50, 50, 50};
	static constexpr x::Color ButtonInactiveColor = {170, 170, 170};
	static constexpr x::Color ButtonBorderColor = {70, 70, 70};
	static constexpr x::Color ButtonFocusBorderColor = {65, 65, 65};
	static constexpr x::Color ButtonPressedBorderColor = {105, 155, 190};
	static constexpr x::Color ButtonInactiveBorderColor = {160, 160, 160};
	static constexpr unsigned ButtonBorderWidth = 2;
	static constexpr Vector2i ButtonSize = {50, 30};

}

constexpr int NoVal = std::numeric_limits<int>::min();

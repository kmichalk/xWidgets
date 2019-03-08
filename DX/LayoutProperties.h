#pragma once

namespace x::ui
{
	enum class Side: uint8_t {
		//None,
		Left,
		Right,
		Top,
		Bottom
		/*All = Left | Right | Top | Bottom,
		LTCorner = Top | Left,
		RTCorner = Top | Right,
		LBCorner = Bottom | Left,
		RBCorner = Bottom | Right,
		Horizontal = Top | Bottom,
		Vertical = Left | Right*/
	};

	struct alignas(sizeof(int)) Anchor {
		enum class Mode : uint8 {
			None, Pixel, Percent, Stick
		};

		

		static constexpr int UNSET = std::numeric_limits<int>::min();
		int left = 0;
		int right = 0;
		int top = 0;
		int bottom = 0;
		Mode leftMode = Mode::None;
		Mode rightMode = Mode::None;
		Mode topMode = Mode::None;
		Mode bottomMode = Mode::None;

		__forceinline constexpr bool leftEnabled() const noexcept {
			return leftMode != Mode::None;
		}

		__forceinline constexpr bool rightEnabled() const noexcept {
			return rightMode != Mode::None;
		}

		__forceinline constexpr bool topEnabled() const noexcept {
			return topMode != Mode::None;
		}

		__forceinline constexpr bool bottomEnabled() const noexcept {
			return bottomMode != Mode::None;
		}

		__forceinline constexpr bool horizontalEnabled() const noexcept {
			return leftMode != Mode::None && rightMode != Mode::None;
		}

		__forceinline constexpr bool verticalEnabled() const noexcept {
			return topMode != Mode::None && bottomMode != Mode::None;
		}

		__inline constexpr void setAllModes(Mode mode) noexcept {
			leftMode = mode;
			rightMode = mode;
			topMode = mode;
			bottomMode = mode;
		}

		void set(Side side, int distance, Mode mode = Mode::Pixel) {
			switch (side) {
			case Side::Left:
				left = distance;
				leftMode = Mode::Pixel;
				break;
			case Side::Right:
				right = distance;
				rightMode = Mode::Pixel;
				break;
			case Side::Top:
				top = distance;
				topMode = Mode::Pixel;
				break;
			case Side::Bottom:
				bottom = distance;
				bottomMode = Mode::Pixel;
				break;
			default:
				break;
			}
		}

		void unset(Side side) {
			switch (side) {
			case Side::Left:
				left = 0;
				leftMode = Mode::None;
				break;
			case Side::Right:
				right = 0;
				rightMode = Mode::None;
				break;
			case Side::Top:
				top = 0;
				topMode = Mode::None;
				break;
			case Side::Bottom:
				bottom = 0;
				bottomMode = Mode::None;
				break;
			default:
				break;
			}
		}

		void unset() {			
			left = 0;
			leftMode = Mode::None;			
			right = 0;
			rightMode = Mode::None;			
			top = 0;
			topMode = Mode::None;			
			bottom = 0;
			bottomMode = Mode::None;
		}
	};

	//struct Anchor {
	//	static constexpr int UNSET = std::numeric_limits<int>::min();
	//	int left = UNSET;
	//	int right = UNSET;
	//	int top = UNSET;
	//	int bottom = UNSET;
	//};


	struct Margin {
		int left;
		int right;
		int top;
		int bottom;
	};

	struct LayoutProperties {
		Anchor anchor = {};
		Vector2i sizeMin = {0, 0};
		Vector2i sizeMax = Vector2i::max();
		Margin margin;
	};

	

	/*__forceinline AnchorSide operator | (AnchorSide left, AnchorSide right) {
		return AnchorSide((uint8_t)left | (uint8_t)right);
	}

	__forceinline AnchorSide operator & (AnchorSide left, AnchorSide right) {
		return AnchorSide((uint8_t)left & (uint8_t)right);
	}

	__forceinline AnchorSide operator ^ (AnchorSide left, AnchorSide right) {
		return AnchorSide((uint8_t)left ^ (uint8_t)right);
	}

	__forceinline void operator |= (AnchorSide& left, AnchorSide right) {
		(uint8_t&)left |= (uint8_t)right;
	}

	__forceinline void operator &= (AnchorSide& left, AnchorSide right) {
		(uint8_t&)left &= (uint8_t)right;
	}

	__forceinline void operator ^= (AnchorSide& left, AnchorSide right) {
		(uint8_t&)left ^= (uint8_t)right;
	}*/
}

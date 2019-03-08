#pragma once

namespace x
{
	template<class _Type>
	struct alignas(1) Color3
	{
		_Type r;
		_Type g;
		_Type b;

		__forceinline constexpr Color3() noexcept:
			r(0),
			g(0),
			b(0)
		{ }

		__forceinline constexpr Color3(Color3 const&) = default;

		__forceinline constexpr Color3(Color3&&) = default;

		__forceinline constexpr Color3(_Type r, _Type g, _Type b) noexcept:
			r(r),
			g(g),
			b(b)
		{ }

		Color3& operator=(Color3 const&) = default;
		Color3& operator=(Color3&&) = default;
	};

	template<class _Type>
	struct alignas(1) Color4
	{
		static constexpr _Type MIN = _Type(0);
		static constexpr _Type MAX = std::is_floating_point_v<_Type> ? _Type(1.0) : _Type(255);

		_Type r;
		_Type g;
		_Type b;
		_Type a;

		constexpr Color4() noexcept:
			r(0),
			g(0),
			b(0),
			a(MAX) {
		}

		constexpr Color4(_Type r, _Type g, _Type b, _Type a = MAX) noexcept:
			r(r),
			g(g),
			b(b),
			a(a){
		}

		constexpr Color4(Color4 const&) noexcept = default;

		constexpr Color4(Color4&&) noexcept = default;

		constexpr Color4(Color3<_Type> const& other) noexcept:
			r(other.r),
			g(other.g),
			b(other.b),
			a(MAX) {
		}

		explicit Color4(int32_t value) noexcept {
			*reinterpret_cast<int32_t*>(this) = value;
		}

		explicit Color4(uint32_t value) noexcept {
			*reinterpret_cast<uint32_t*>(this) = value;
		}

		Color4& operator=(Color4 const&) = default;

		Color4& operator=(Color4&&) = default;

		inline constexpr static Color4 gray(_Type value, _Type alpha = MAX) noexcept {
			return Color4(value, value, value, alpha);
		}
	};

	/*struct alignas(1) Color3 {
		float r;
		float g;
		float b;

		__forceinline constexpr Color3() noexcept:
			r(0),
			g(0),
			b(0) {
		}

		__forceinline constexpr Color3(Color3 const&) = default;

		__forceinline constexpr Color3(Color3&&) = default;

		__forceinline constexpr Color3(float r, float g, float b) noexcept:
			r(r),
			g(g),
			b(b) {
		}

		Color3& operator=(Color3 const&) = default;
		Color3& operator=(Color3&&) = default;
	};

	
	struct alignas(1) Color4 {
		static constexpr uint8 MIN = 0u;
		static constexpr uint8 MAX = 255u;

		float r;
		float g;
		float b;
		float a;

		constexpr Color4() noexcept:
			r(MIN),
			g(MIN),
			b(MIN),
			a(MAX) {
		}

		constexpr Color4(float r, float g, float b, float a = 1.0f) noexcept:
			r(r),
			g(g),
			b(b),
			a(a) {
		}

		constexpr Color4(int r, int g, int b, int a = MAX) noexcept:
			r((float)r / MAX),
			g((float)g / MAX),
			b((float)b / MAX),
			a((float)a / MAX) {
		}

		constexpr Color4(unsigned r, unsigned g, unsigned b, unsigned a = MAX) noexcept:
			r((float)r / MAX),
			g((float)g / MAX),
			b((float)b / MAX),
			a((float)a / MAX) {
		}

		constexpr Color4(Color4 const&) noexcept = default;

		constexpr Color4(Color4&&) noexcept = default;

		constexpr Color4(Color3 const& other) noexcept:
			r(other.r),
			g(other.g),
			b(other.b),
			a(MAX) {
		}

		explicit Color4(int32_t value) noexcept {
			*reinterpret_cast<int32_t*>(this) = value;
		}

		explicit Color4(uint32_t value) noexcept {
			*reinterpret_cast<uint32_t*>(this) = value;
		}

		Color4& operator=(Color4 const&) = default;

		Color4& operator=(Color4&&) = default;

		inline constexpr static Color4 gray(_Type value, _Type alpha = MAX) noexcept {
			return Color4(value, value, value, alpha);
		}
	};*/

	using Color3b = Color3<uint8_t>;
	using Color3i = Color3<int>;
	using Color3f = Color3<float>;
	using Color3d = Color3<double>;
	using Color4b = Color4<uint8_t>;
	using Color4i = Color4<int>;
	using Color4f = Color4<float>;
	using Color4d = Color4<double>;
	using Color = Color4b;


	class Colors
	{
	public:
		static constexpr Color Maroon = {128, 0, 0};
		static constexpr Color DarkRed = {139, 0, 0};
		static constexpr Color Brown = {165, 42, 42};
		static constexpr Color Firebrick = {178, 34, 34};
		static constexpr Color Crimson = {220, 20, 60};
		static constexpr Color Red = {255, 0, 0};
		static constexpr Color Tomato = {255, 99, 71};
		static constexpr Color Coral = {255, 127, 80};
		static constexpr Color IndianRed = {205, 92, 92};
		static constexpr Color LightCoral = {240, 128, 128};
		static constexpr Color DarkSalmon = {233, 150, 122};
		static constexpr Color Salmon = {250, 128, 114};
		static constexpr Color LightSalmon = {255, 160, 122};
		static constexpr Color OrangeRed = {255, 69, 0};
		static constexpr Color DarkOrange = {255, 140, 0};
		static constexpr Color Orange = {255, 165, 0};
		static constexpr Color Gold = {255, 215, 0};
		static constexpr Color DarkGoldenRod = {184, 134, 11};
		static constexpr Color GoldenRod = {218, 165, 32};
		static constexpr Color PaleGoldenRod = {238, 232, 170};
		static constexpr Color DarkKhaki = {189, 183, 107};
		static constexpr Color Khaki = {240, 230, 140};
		static constexpr Color Olive = {128, 128, 0};
		static constexpr Color Yellow = {255, 255, 0};
		static constexpr Color YellowGreen = {154, 205, 50};
		static constexpr Color DarkOliveGreen = {85, 107, 47};
		static constexpr Color OliveDrab = {107, 142, 35};
		static constexpr Color LawnGreen = {124, 252, 0};
		static constexpr Color ChartReuse = {127, 255, 0};
		static constexpr Color GreenYellow = {173, 255, 47};
		static constexpr Color DarkGreen = {0, 100, 0};
		static constexpr Color Green = {0, 128, 0};
		static constexpr Color ForestGreen = {34, 139, 34};
		static constexpr Color Lime = {0, 255, 0};
		static constexpr Color LimeGreen = {50, 205, 50};
		static constexpr Color LightGreen = {144, 238, 144};
		static constexpr Color PaleGreen = {152, 251, 152};
		static constexpr Color DarkSeaGreen = {143, 188, 143};
		static constexpr Color MediumSpringGreen = {0, 250, 154};
		static constexpr Color SpringGreen = {0, 255, 127};
		static constexpr Color SeaGreen = {46, 139, 87};
		static constexpr Color MediumAquaMarine = {102, 205, 170};
		static constexpr Color MediumSeaGreen = {60, 179, 113};
		static constexpr Color LightSeaGreen = {32, 178, 170};
		static constexpr Color DarkSlateGray = {47, 79, 79};
		static constexpr Color Teal = {0, 128, 128};
		static constexpr Color DarkCyan = {0, 139, 139};
		static constexpr Color Aqua = {0, 255, 255};
		static constexpr Color Cyan = {0, 255, 255};
		static constexpr Color LightCyan = {224, 255, 255};
		static constexpr Color DarkTurquoise = {0, 206, 209};
		static constexpr Color Turquoise = {64, 224, 208};
		static constexpr Color MediumTurquoise = {72, 209, 204};
		static constexpr Color PaleTurquoise = {175, 238, 238};
		static constexpr Color AquaMarine = {127, 255, 212};
		static constexpr Color PowderBlue = {176, 224, 230};
		static constexpr Color CadetBlue = {95, 158, 160};
		static constexpr Color SteelBlue = {70, 130, 180};
		static constexpr Color CornFlowerBlue = {100, 149, 237};
		static constexpr Color DeepSkyBlue = {0, 191, 255};
		static constexpr Color DodgerBlue = {30, 144, 255};
		static constexpr Color LightBlue = {173, 216, 230};
		static constexpr Color SkyBlue = {135, 206, 235};
		static constexpr Color LightSkyBlue = {135, 206, 250};
		static constexpr Color MidnightBlue = {25, 25, 112};
		static constexpr Color Navy = {0, 0, 128};
		static constexpr Color DarkBlue = {0, 0, 139};
		static constexpr Color MediumBlue = {0, 0, 205};
		static constexpr Color Blue = {0, 0, 255};
		static constexpr Color RoyalBlue = {65, 105, 225};
		static constexpr Color BlueViolet = {138, 43, 226};
		static constexpr Color Indigo = {75, 0, 130};
		static constexpr Color DarkSlateBlue = {72, 61, 139};
		static constexpr Color SlateBlue = {106, 90, 205};
		static constexpr Color MediumSlateBlue = {123, 104, 238};
		static constexpr Color MediumPurple = {147, 112, 219};
		static constexpr Color DarkMagenta = {139, 0, 139};
		static constexpr Color DarkViolet = {148, 0, 211};
		static constexpr Color DarkOrchid = {153, 50, 204};
		static constexpr Color MediumOrchid = {186, 85, 211};
		static constexpr Color Purple = {128, 0, 128};
		static constexpr Color Thistle = {216, 191, 216};
		static constexpr Color Plum = {221, 160, 221};
		static constexpr Color Violet = {238, 130, 238};
		static constexpr Color Magenta = {255, 0, 255};
		static constexpr Color Orchid = {218, 112, 214};
		static constexpr Color MediumVioletRed = {199, 21, 133};
		static constexpr Color PaleVioletRed = {219, 112, 147};
		static constexpr Color DeepPink = {255, 20, 147};
		static constexpr Color HotPink = {255, 105, 180};
		static constexpr Color LightPink = {255, 182, 193};
		static constexpr Color Pink = {255, 192, 203};
		static constexpr Color AntiqueWhite = {250, 235, 215};
		static constexpr Color Beige = {245, 245, 220};
		static constexpr Color Bisque = {255, 228, 196};
		static constexpr Color BlanchedAlmond = {255, 235, 205};
		static constexpr Color Wheat = {245, 222, 179};
		static constexpr Color CornSilk = {255, 248, 220};
		static constexpr Color LemonChiffon = {255, 250, 205};
		static constexpr Color LightGoldenRodYellow = {250, 250, 210};
		static constexpr Color LightYellow = {255, 255, 224};
		static constexpr Color SaddleBrown = {139, 69, 19};
		static constexpr Color Sienna = {160, 82, 45};
		static constexpr Color Chocolate = {210, 105, 30};
		static constexpr Color Peru = {205, 133, 63};
		static constexpr Color SandyBrown = {244, 164, 96};
		static constexpr Color BurlyWood = {222, 184, 135};
		static constexpr Color Tan = {210, 180, 140};
		static constexpr Color RosyBrown = {188, 143, 143};
		static constexpr Color Moccasin = {255, 228, 181};
		static constexpr Color NavajoWhite = {255, 222, 173};
		static constexpr Color PeachPuff = {255, 218, 185};
		static constexpr Color MistyRose = {255, 228, 225};
		static constexpr Color LavenderBlush = {255, 240, 245};
		static constexpr Color Linen = {250, 240, 230};
		static constexpr Color OldLace = {253, 245, 230};
		static constexpr Color PapayaWhip = {255, 239, 213};
		static constexpr Color SeaShell = {255, 245, 238};
		static constexpr Color MintCream = {245, 255, 250};
		static constexpr Color SlateGray = {112, 128, 144};
		static constexpr Color LightSlateGray = {119, 136, 153};
		static constexpr Color LightSteelBlue = {176, 196, 222};
		static constexpr Color Lavender = {230, 230, 250};
		static constexpr Color FloralWhite = {255, 250, 240};
		static constexpr Color AliceBlue = {240, 248, 255};
		static constexpr Color GhostWhite = {248, 248, 255};
		static constexpr Color Honeydew = {240, 255, 240};
		static constexpr Color Ivory = {255, 255, 240};
		static constexpr Color Azure = {240, 255, 255};
		static constexpr Color Snow = {255, 250, 250};
		static constexpr Color Black = {0, 0, 0};
		static constexpr Color DimGray = {105, 105, 105};
		static constexpr Color Gray = {128, 128, 128};
		static constexpr Color DarkGray = {169, 169, 169};
		static constexpr Color Silver = {192, 192, 192};
		static constexpr Color LightGray = {211, 211, 211};
		static constexpr Color Gainsboro = {220, 220, 220};
		static constexpr Color WhiteSmoke = {245, 245, 245};
		static constexpr Color White = {255, 255, 255};
	};
		
}

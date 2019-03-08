#pragma once


namespace x
{
	template<class _Type>
	struct Vector2
	{
		_Type x;
		_Type y;

		__forceinline constexpr Vector2() noexcept:
			x(0),
			y(0)
		{ }

		template<class _Other>
		__forceinline constexpr Vector2(Vector2<_Other> const& other) noexcept:
			x(_Type(other.x)),
			y(_Type(other.y))
		{ }

		__forceinline constexpr Vector2(_Type x, _Type y) noexcept:
			x(x),
			y(y)
		{ }

		__forceinline constexpr Vector2 operator+(Vector2 const& other) const noexcept {
			return {x + other.x, y + other.y};
		}

		__forceinline constexpr Vector2& operator+=(Vector2 const& other) noexcept {
			x += other.x;
			y += other.y;
			return *this;
		}

		__forceinline constexpr Vector2 operator-(Vector2 const& other) const noexcept {
			return {x - other.x, y - other.y};
		}

		__forceinline constexpr Vector2& operator-=(Vector2 const& other) noexcept {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		template<class _Value>
		__forceinline constexpr Vector2 operator*(_Value value) const noexcept {
			return {x*value, y*value};
		}

		template<class _Value>
		__forceinline constexpr Vector2& operator*=(_Value value) noexcept {
			x *= value;
			y *= value;
			return *this;
		}

		template<class _Value>
		__forceinline constexpr Vector2 operator/(_Value value) const noexcept {
			return {x/value, y/value};
		}

		template<class _Value>
		__forceinline constexpr Vector2& operator/=(_Value value) noexcept {
			x /= value;
			y /= value;
			return *this;
		}

		__forceinline _Type operator*(Vector2 other) const noexcept {
			return x * other.x + y * other.y;
		}

		__forceinline constexpr bool operator==(Vector2 const& other) const noexcept {
			return x == other.x && y == other.y;
		}

		__forceinline constexpr bool operator!=(Vector2 const& other) const noexcept {
			return x != other.x || y != other.y;
		}

		__forceinline _Type length() const {
			return hypot(x, y);
		}

		inline static constexpr Vector2 min() noexcept {
			return Vector2{std::numeric_limits<_Type>::lowest(), std::numeric_limits<_Type>::lowest()};
		}

		inline static constexpr Vector2 max() noexcept {
			return Vector2{std::numeric_limits<_Type>::max(), std::numeric_limits<_Type>::max()};
		}
	};

	using Vector2f = Vector2<float>;
	using Vector2d = Vector2<double>;
	using Vector2u = Vector2<unsigned>;
	using Vector2i = Vector2<int>;
}
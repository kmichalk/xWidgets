#pragma once

namespace x::core
{
	template<class _Type, auto _get = 0, auto _set = 0>
	class Property
	{
		using Owner = x::owner_of_t<decltype(_get)>;
		using Ret = x::return_type_of_t<decltype(_get)>;
		using Arg = x::argument_of_t<1, decltype(_set)>;

		Owner* _owner;

	public:
		Property(Owner* owner):
			_owner(owner)
		{ }

		Property(Property const& other) = default;

		Property(Property&& other) = default;

		~Property() = default;

		__forceinline Property& operator=(Arg value) & {
			(_owner->*_set)(value);
			return *this;
		}

		__forceinline operator Ret() {
			return (_owner->*_get)();
		}
	};
}

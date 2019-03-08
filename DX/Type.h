#pragma once


namespace x::core
{
	using type_t = uint32_t;

	class Type
	{
	protected:
		inline static type_t lastID = 1;
	public:
		type_t const id;

		template<class _Class>
		static type_t of() noexcept;

		Type();
		Type(type_t id);
		Type(Type const& other) = default;
		Type(Type&& other) = default;
		Type& operator=(Type const& other);
		Type& operator=(Type&& other);
		bool undefined() const;
		bool operator==(Type const& other) const;
		bool operator!=(Type const& other) const;
	};

	template<class _Class>
	class _Type: public Type
	{
	public:
		inline static type_t const typeID = Type::lastID++;
	};

	template<class _Class>
	__forceinline type_t Type::of() noexcept {
		return _Type<_Class>::typeID;
	}

	__forceinline x::core::Type::Type():
		id(0) {
	}

	__forceinline x::core::Type::Type(type_t id) :
		id(id) {
	}

	__forceinline x::core::Type & x::core::Type::operator=(Type const & other) {
		const_cast<type_t&>(id) = other.id;
	}

	__forceinline x::core::Type & x::core::Type::operator=(Type && other) {
		const_cast<type_t&>(id) = other.id;
	}

	__forceinline bool x::core::Type::undefined() const {
		return id == 0;
	}

	__forceinline bool Type::operator==(Type const& other) const {
		return id == other.id;
	}

	__forceinline bool Type::operator!=(Type const& other) const {
		return id != other.id;
	}
}

#pragma once

namespace x::ui
{
	class Component;

	class ComponentCollection
	{
		x::vector<Component*> const& _data;
	public:
		ComponentCollection(x::vector<Component*> const& data);
		ComponentCollection(ComponentCollection const&) = default;
		ComponentCollection(ComponentCollection&&) = default;
		ComponentCollection& operator=(ComponentCollection const&) = default;
		ComponentCollection& operator=(ComponentCollection&&) = default;
		~ComponentCollection() = default;
		Component* find(std::string const& name) const;
		Component* recursiveFind(std::string const& name) const;
		auto begin() const;
		auto end() const;
	};
}

///////////////////////////////////////////////////////////////////////////////////////////////

__forceinline auto x::ui::ComponentCollection::begin() const {
	return _data.begin();
}

///////////////////////////////////////////////////////////////////////////////////////////////

__forceinline auto x::ui::ComponentCollection::end() const {
	return _data.end();
}

#include "stdafx.h"
#include "ComponentCollection.h"
#include "Component.h"


x::ui::ComponentCollection::ComponentCollection(x::vector<Component*> const& data):
	_data(data)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Component* x::ui::ComponentCollection::find(std::string const & name) const {
	for (auto c : _data) {
		if (c->name() == name)
			return c;
	}
	return nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Component * x::ui::ComponentCollection::recursiveFind(std::string const & name) const {
	for (auto c : _data) {
		if (c->name() == name)
			return c;
		if (auto r = c->components().recursiveFind(name))
			return r;
	}
	return nullptr;
}

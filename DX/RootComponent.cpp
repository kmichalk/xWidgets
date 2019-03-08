#include "stdafx.h"
#include "RootComponent.h"
#include "Window.h"


void x::ui::RootComponent::onParentUpdated(Component * parent) {
	_hidden = false;
	_active = true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::RootComponent::RootComponent(Window * parentWindow):
	Container(parentWindow)
{
	setSize(parentWindow->size());
	onParentUpdated(nullptr);
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::RootComponent::~RootComponent() {
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool x::ui::RootComponent::updateLayout() {
	return updateLayoutImpl();
}

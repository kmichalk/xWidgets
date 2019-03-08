#include "stdafx.h"
#include "Container.h"




//void x::ui::Container::updateLayout(Component * triggerComp) {
//	auto& prop = triggerComp->layoutProperties();	
//	triggerComp->suspend();
//	processAnchor(triggerComp, prop.anchor);
//	triggerComp->resume();
//}

x::ui::Container::Container(Window* parentWindow):
	Component(parentWindow)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////

x::ui::Container::~Container() {
}

//void x::ui::Container::setSize(int width, int height) {
//	Component::setSize(width, height);
//
//}
//
//void x::ui::Container::setWidth(int width) {
//}
//
//void x::ui::Container::setHeight(int height) {
//}

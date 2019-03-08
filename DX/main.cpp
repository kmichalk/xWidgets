#include "stdafx.h"
#include "Application.h"
#include "Button.h"
#include "Property.h"

using namespace x;
using namespace x::ui;

void onWindowClicked(Component* comp, MouseEventData const* event) {
	if (event->button == x::Button::Left && event->ctrl()) {
		auto c = comp->color();
		comp->setColor({(uint8_t)x::random32(0,255), (uint8_t)x::random32(0, 255), (uint8_t)x::random32(0, 255)});
		//std::cout << "click\n";
	}
}

void onButtonClicked(x::ui::Button* button) {
	//std::cout << button->id() << " ";
	button->parentWindow()->root()->components().recursiveFind("d")->move(10, 0);
}

void onEnteredDummy(Component* button) {

}

void onWindowEsc(Window* window, KeyEventData const* data) {
	if (data->key == Key::Escape)
		window->close();
}



//class A {
//	int _value = 0;
//	void _setValue(int value) {
//		_value = value;
//	}
//	int _getValue() const{
//		return _value;
//	}
//public:
//	Property<int, &A::_getValue, &A::_setValue> Value;
//
//	A():
//		Value(this)
//	{ }
//};

//int main() {
//	A a;
//	a.Value = 9;
//	std::cout << a.Value;
//}
//
//int main(int argc, char* argv[]) {
//	std::cout << std::fixed;
//	std::cout.precision(6);
//
//	using namespace x::ui;
//	Application app(argc, argv);
//	auto window = new Window({300, 300}, "GLProj");
//	window->initialize();
//	window->KeyPressed.connect(onWindowEsc);
//	auto root = window->root();
//	root->MousePressed.connect(onWindowClicked);
//	repeat(10000) {
//		auto button = new x::ui::Button;
//		button->Clicked.connect(onButtonClicked);
//		button->setPosition(100, 100);
//		button->layout().setMinSize({100, 100});
//		//button->setAnchor(AnchorSide::Right, 100);
//		root->addComponent(button);
//		button->layout().applyAnchorInCurrentBounds();
//	}
//	app.start(window);
//	exit(EXIT_SUCCESS);
//}


int main(int argc, char* argv[]) {

	using namespace x::ui;
	Application app(argc, argv);
	
	int a = 20;

	auto root = new Container;
	root->setName("root");
	root->setSize(300, 300);
	root->layout().setMinSize({100, 100});
	//root->setColor(Colors::Coral);
	root->setAnchor(Side::Left, a);
	root->setAnchor(Side::Right, a);
	root->setAnchor(Side::Top, a);
	root->setAnchor(Side::Bottom, a);

	auto c1 = new Container;
	c1->setName("c1");
	c1->setSize(200, 200);
	c1->layout().setMinSize({100, 200});
	//c1->setColor(Colors::Aqua);
	//c1->setAnchor(Side::Left, 50);
	c1->setAnchor(Side::Right, a);
	c1->setAnchor(Side::Top, a);
	c1->setAnchor(Side::Bottom, a);

	auto c2 = new Container;
	c2->setName("c2");
	c2->setSize(200, 100);
	c2->layout().setMinSize({200, 0});
	//c2->setColor(Colors::Crimson);
	c2->setAnchor(Side::Left, a);
	c2->setAnchor(Side::Right, a);
	c2->setAnchor(Side::Top, a);
	//c2->setAnchor(Side::Bottom, 50);

	auto b1 = new x::ui::Button;
	b1->setName("b1");
	b1->setAnchor(Side::Left, a);
	b1->setAnchor(Side::Top, a);
	b1->Clicked.connect(onButtonClicked);

	auto d = new Container;
	d->setName("d");
	d->setPosition(100, 100);
	d->setSize(100, 100);
	/*d->setAnchor(Side::Left, 50);
	d->setAnchor(Side::Right, a);
	d->setAnchor(Side::Top, a);
	d->setAnchor(Side::Bottom, a);*/

	auto window = new Window({500, 500}, "");
	window->KeyPressed.connect(onWindowEsc);
	window->initialize();
	auto r = window->root();
	r->addComponent(root);
	r->setBorderWidth(5);
	root->addComponent(c2);
	root->addComponent(c1);
	c1->addComponent(b1);
	r->updateLayout();
	c1->addComponent(d);
	d->layout().applyAnchorInCurrentBounds();
	d->layout().unsetAnchor(Side::Left);
	//window->setIgnoreLayoutSize(true);
	//r->MousePressed.connect(onWindowClicked);

	app.start(window);
	exit(EXIT_SUCCESS);
}


Vector2i __declspec(noinline) get() {
	Vector2i v;
	v.x = 1;
	return v;
}


void __declspec(noinline) func(Vector2i v) {
	v.y = 1;
}

//int main(int argc, char* argv[]) {
//
//	/*func(get());
//	return 0;*/
//
//	using namespace x::ui;
//	Application app(argc, argv);
//	auto window = new Window({300, 300}, "GLProj");
//	window->initialize();
//	window->KeyPressed.connect(onWindowEsc);
//	auto root = window->root();
//	root->MousePressed.connect(onWindowClicked);
//
//	int sizex = 50;
//	int sizey = 50;
//	int n = 5;
//
//	for (int i = 0; i < n; ++i) {
//		for (int k = 0; k < n; ++k) {
//			auto button = new x::ui::Button;
//			button->setSize(sizex, sizey);
//			//button->setColor(Colors::White);
//			//button->setBorderWidth(3);
//			//repeat(1000)
//				//button->MouseEntered.connect(onEnteredDummy);
//				button->Clicked.connect(onButtonClicked);
//			button->setPosition(i*sizex + 2*i+10, k*sizey+2*k+10);
//			//button->setAnchor(Side::Right, i*sizex);
//			//button->setAnchor(Side::Left, 10);
//			root->addComponent(button);
//		}
//	}
//	app.start(window);
//	exit(EXIT_SUCCESS);
//}


//int main(int argc, char* argv[]) {
//	using namespace x::ui;
//	Application app(argc, argv);
//	auto window = new Window({600, 600}, "GLProj");
//	window->initialize();
//	auto root = window->root();
//	root->MousePressed.connect(onWindowClicked);
//	auto button = new x::ui::Button;
//	button->Clicked.connect(onButtonClicked);
//	button->setPosition(100, 100);
//	root->addComponent(button);
//	app.start(window);
//	exit(EXIT_SUCCESS);
//}

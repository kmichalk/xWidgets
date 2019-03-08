#pragma once

#include "_Component.h"

namespace x::ui
{
	class ApplicationComponent: public _Component<ApplicationComponent>
	{
		using _Component<ApplicationComponent>::copy;
	protected:
		bool _initialized;
	public:
		ApplicationComponent();		
		virtual ~ApplicationComponent() = default;
		virtual void initialize();
		bool isInitialized() const;
	};
}

#pragma once

#define _asBase(...) static_cast<_Base*>(__VA_ARGS__)
#define _asComp(...) static_cast<Component<_Base>*>(__VA_ARGS__)

namespace x::ui
{
	class _ComponentBase
	{
	public:
		using id_t = uint32_t;
	private:
		inline static id_t _lastID = 0;
	protected:
		inline static id_t nextID() noexcept {
			return _lastID++;
		}
	};

	template<class _Base>
	class _Component: public _ComponentBase
	{
		_Base* _parent;
		x::vector<_Base*> _children;
		Type _type;
		id_t _id;

		using _ComponentBase::nextID;

	protected:
		template<class _Class>
		__forceinline void initializeType() {
			_type = Type::of<_Class>();
		}

		virtual void onParentUpdated(_Base* parent){}

	public:
		_Component():
			_parent(nullptr),
			_children(),
			//_type omitted on purpose
			_id(nextID())
		{ }

		_Component(_Base* parent):
			_parent(parent),
			_children(),
			//_type omitted on purpose
			_id(nextID())
		{ 
			if (parent != nullptr)
				parent->addComponent(static_cast<_Base*>(this));
		}

		/*Component(Component const& other):
			_parent(other._parent),
			_children(),
			_type(other._type),
			_id(nextID())
		{
			_children.resize(other._children.size());
			auto i = _children.pbegin();
			for (auto c : other._children) {
				*i = c->copy();
				++i;
			}
		}*/
		
		virtual ~_Component() {
			destruct();
		}

		virtual void destruct() {
			clearComponents();
		}

		void orphan() {
			if (_parent != nullptr) {
				_parent->_children.remove(this);
				_parent = nullptr;
			}
		}

		__forceinline _Base* parent() const {
			return _parent;
		}

		__forceinline x::vector<_Base*> const& children() const {
			return _children;
		}

		__forceinline id_t id() const {
			return _id;
		}

		virtual void addComponent(_Base* child) {
			if (child == nullptr)
				return;
			_children.push_back(child);
			child->_parent = static_cast<_Base*>(this);
			static_cast<_Component*>(child)->onParentUpdated(static_cast<_Base*>(this));
		}

		__forceinline void addComponents(x::vector<_Base*> children) {
			_children.append(children);
		}

		/*__forceinline void addComponentsOf(_Base* other) {
			_children.append(other->_children);
		}*/

		__forceinline void swapComponents(_Base* other) {
			_children.swap(other->_children);
		}

		void clearComponents() {
			_children.call_delete().clear();
		}

		__forceinline void removeComponent(_Base* comp) {
			_children.remove(comp);
		}

		/*_Base* child(size_t i) const {
			return _children.at(i, nullptr);
		}*/

		__forceinline bool isParentOf(_Base* child) const {
			return _children.contains(child);
		}

		__forceinline Type type() const {
			return _type;
		}

		template<class _Comp>
		__forceinline bool is() const {
			return _type == Type::of<_Comp>();
		}

		template<class _Comp>
		_Comp* cast() {
			return _type == Type::of<_Comp>() ? static_cast<_Comp*>(this) : nullptr;
		}

		template<class _Comp>
		_Comp* cast() const {
			return _type == Type::of<_Comp>() ? static_cast<_Comp const*>(this) : nullptr;
		}

		virtual _Base* copy() const {
			return nullptr;
		}
	};
}

#define SetType initializeType<std::remove_pointer_t<decltype(this)>>()
#pragma once

class Obj {
public:
	void f(int){}
};

namespace x::core
{
	struct _Handler {
		void* function;
		void* object;
		//void* handler;
	};

	template<class... _Arg>
	class Event
	{
		class Handler;

		struct FakeOwner {};
		using fake_m = void(__thiscall FakeOwner::*)(_Arg...);
		using handler_f = void(*)(_Arg...);

		x::vector<_Handler> _handlers;

	public:
		void __declspec(noinline) __thiscall invoke(_Arg... args) const {
			/*constexpr size_t HANDLER_SIZE = sizeof(_Handler);
			_Handler* _end;
			__asm {
				mov		eax, [ecx]_handlers.size_
				cmp		eax, 0
				je		_RET_
				mov		esi, [ecx]_handlers.data_
				mov		ebx, HANDLER_SIZE
				xor		edx, edx
				mul		ebx
				add		eax, esi
				mov		_end, eax
				_LOOP_ :
				push	dword ptr[ebp + 16]
					call	dword ptr[esi]
					add		esi, HANDLER_SIZE
					cmp		esi, _end
					jne		_LOOP_
					_RET_ :
			}*/

			for (_Handler const& h : _handlers)
				if (h.object == nullptr)
					reinterpret_cast<handler_f const&>(h.function)(args...);
				else
					(reinterpret_cast<FakeOwner*>(h.object)->*reinterpret_cast<fake_m const&>(h.function))(args...);
		}

		void operator()(_Arg... args) const {
			for (_Handler const& h : _handlers)
				if (h.object == nullptr)
					reinterpret_cast<handler_f const&>(h.function)(args...);
				else
					(reinterpret_cast<FakeOwner*>(h.object)->*reinterpret_cast<fake_m const&>(h.function))(args...);
		}

		/*void invoke(_Arg... args) const {
			for (_Handler const& h : _handlers)
				(static_cast<Handler const&>(h).*reinterpret_cast<handler_f const&>(h.handler))(args...);
		}*/

		template<class _Owner>
		void connect(_Owner* object, void(_Owner::*method)(_Arg...)) {
			_handlers.push_back(
				_Handler{
					reinterpret_cast<void*&>(method),
					reinterpret_cast<void*>(object)
				}
			);
		}

		void connect(void(*function)(_Arg...)) {
			_handlers.push_back(
				_Handler{
					reinterpret_cast<void*>(function),
					nullptr
				}
			);
		}

		void connectUnique(void(*function)(_Arg...)) {			
			_handlers.push_back(
				_Handler{
					reinterpret_cast<void*>(function),
					nullptr
				}
			);
		}

		void disconnectAll() {
			_handlers.clear();
		}

		template<class _Owner>
		void disconnect(_Owner* object, void(_Owner::*method)(_Arg...)) {
			_handlers.remove_if(
				[object, method](_Handler& h) {
				return
					reinterpret_cast<void*&>(method) == h.function &&
					reinterpret_cast<void*>(object) == h.object;
			});
		}

		template<class _Owner>
		void disconnect(void(_Owner::*method)(_Arg...)) {
			_handlers.remove_if(
				[method](_Handler& h) {
				return
					reinterpret_cast<void*&>(method) == h.function;
			});
		}

		void disconnect(void(*function)(_Arg...)) {
			_handlers.remove_if(
				[function](_Handler& h) {
				return
					reinterpret_cast<void*>(function) == h.function;
			});
		}

		template<class _Owner>
		void disconnect(_Owner* object) {
			_handlers.remove_if(
				[object](_Handler& h) {
				return
					reinterpret_cast<void*>(object) == h.object;
			});
		}


		__forceinline explicit operator bool() const {
			return _handlers.nonempty();
		}
	};


	//template<class _Owner, class... _Arg>
	//class PrivateEvent: public Event<_Arg...>
	//{
	//	friend _Owner;
	//	
	//	using Event<_Arg...>::operator();
	//	using Event<_Arg...>::invoke;
	//	using Event<_Arg...>::disconnect;
	//	using Event<_Arg...>::disconnectAll;
	//};

}

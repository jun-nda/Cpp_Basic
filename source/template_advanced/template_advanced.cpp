#include <iostream>
#include <type_traits>
#include <vector>
#include <cassert>

using std::cout;
using std::endl;
using std::vector;
using std::remove_reference;
using std::is_reference;
using std::move;
using std::forward;


template<typename RetVal, typename...Args>
class IDelegate
{
public:
	virtual RetVal Excute(Args&&... args) = 0;
};

template<typename TLambda, typename RetVal, typename... Args>
class LambdaDelegate;

template<typename TLambda, typename RetVal, typename... Args>
class LambdaDelegate<TLambda, RetVal(Args...)> : public IDelegate<RetVal, Args...>
{
public:
	explicit LambdaDelegate(TLambda&& lambda)
		:m_Lambda(std::forward<TLambda>(lambda))
	{

	}

	RetVal Excute(Args&&... args) override
	{
		return (RetVal)((m_Lambda)(args...));
	}
private:
	TLambda m_Lambda;
};

template<typename RetVal, typename... Args>
class Delegate
{
public:
	using IDelegateT = IDelegate<RetVal, Args...>;

	template<typename TLambda, typename... Args2>
	static Delegate CreateLambda(TLambda&& lambda)
	{
		Delegate handler;
		handler.m_pAllocator = new LambdaDelegate<TLambda, RetVal(Args...)>(std::forward<TLambda>(lambda));
		return handler;
	}

	template<typename LambdaType, typename... Args2>
	inline void BindLambda(LambdaType&& lambda, Args2&&... args)
	{
		*this = CreateLambda<LambdaType>(std::forward<LambdaType>(lambda));
	}

	RetVal Execute(Args... args) const
	{
		assert(m_Allocator.HasAllocation( ) && "Delegate is not bound");
		return Getde
	}

private:
	IDelegateT* m_pAllocator;
};

//Base type for delegates
//template<typename RetVal, typename ...Args>
//class IDelegate
//{
//public:
//	virtual RetVal Execute(Args&& ...args) = 0;
//};
//
//template<typename TLambda, typename RetVal, typename... Args>
//class LambdaDelegate;
//
//template<typename TLambda, typename RetVal, typename... Args>
//class LambdaDelegate<TLambda, RetVal(Args...)> : public IDelegate<RetVal, Args...>
//{
//public:
//	explicit LambdaDelegate(TLambda&& lambda) :
//		m_pLambda(std::forward<TLambda>(lambda))
//		//m_Payload(std::forward<Args2>(args)...)
//	{}
//
//	RetVal Execute(Args&&... args) override
//	{
//		//return Execute_Internal(args...);
//		return (RetVal)((m_pLambda)(args...));
//	}
//
//private:
//	template<std::size_t... Is>
//	RetVal Execute_Internal(Args&&... args)
//	{
//		//return (RetVal)((*m_pLambda)(args..., std::get<Is>(m_Payload)...));
//		return (RetVal)((m_pLambda)(args...));
//	}
//
//	TLambda m_pLambda;
//	//std::tuple<Args2...> m_Payload;
//};


//Delegate that can be bound to by just ONE object
//template<typename RetVal, typename ...Args>
//class SinglecastDelegate
//{
//public:
//	SinglecastDelegate() {}
//	~SinglecastDelegate() {}
//
//	//Create a SinglecastDelegate instance bound with a lambda
//	template<typename LambdaType, typename... Args2>
//	static SinglecastDelegate CreateLambda(LambdaType&& lambda)
//	{
//		SinglecastDelegate NewDelegate;
//		NewDelegate.BindLambda(std::forward<LambdaType>(lambda));
//		return NewDelegate;
//	}
//	//Bind a lambda
//	template<typename LambdaType>
//	void BindLambda(LambdaType&& lambda)
//	{
//		m_pEvent = new LambdaDelegate<LambdaType, RetVal(Args...)>(std::forward<LambdaType>(lambda));
//	}
//
//	//Execute the function
//	RetVal Execute(Args&& ...args) const
//	{
//		assert(m_pEvent != nullptr);
//		return m_pEvent->Execute(std::forward<Args>(args)...);
//	}
//private:
//
//	IDelegate<RetVal, Args...>* m_pEvent;
//};


//template<typename TLambda, typename RetVal, typename... Args>
//class LambdaDelegate
//{
//public:
//	explicit LambdaDelegate(TLambda&& lambda)
//		:m_Lambda(std::forward<TLambda>(lambda))
//	{
//		cout << typeid(RetVal).name( ) << endl;
//	}
//
//	RetVal Excute(Args&&... args) override
//	{
//		return (RetVal)((m_Lambda)(std::forward<Args>(args)...));
//	}
//private:
//	TLambda m_Lambda;
//};
//
//template<typename RetVal, typename... Args>
//void test( ){
//
//}

struct Foo
{
	int Bar(float a)
	{
		printf("Raw delegate parameter: %f", a);
		return 10;
	}
};

int main( ){

	{
		//SinglecastDelegate<int, float> del;
		//del.BindLambda([](float a) 
		//	{
		//		std::cout << "Lambda delegate parameter: " << a << std::endl;
		//		return 10;
		//	});
		//std::cout << "Lambda delegate return value: " << del.Execute(20) << std::endl;
		Delegate<int, float, float> del;
		Foo foo;
		cout << typeid(int(float)).name( ) << endl;
		del.BindLambda([](float a, float b){
			return 40;
			});
		//int out = del.Execute(20);
		//printf("Lambda delegate return value:  %d", out);
	}

	{
		//MulticastDelegate<float> del;
		//del.AddLambda([](float a)
		//	{
		//		printf("Lambda delegate parameter: %f", a);
		//	}, 90);
		//Foo foo;
		//del.AddRaw(&foo, &Foo::Bar);
		//del.Broadcast(20);
	}


	return 0;
}
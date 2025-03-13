#include <iostream>
#include <type_traits>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::remove_reference;
using std::is_reference;
using std::move;
using std::forward;

// 尾置返回类型，因为返回类型一般写在参数列表前面，这里需要通过参数来推断返回类型
// 返回一个元素的引用
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg){
	return *beg;
}

// 返回一个元素的拷贝
template <typename It>
auto fcn2(It beg, It end) ->
	typename remove_reference<decltype(*beg)>::type
{
	return *beg;
}

template <typename T> void f3( T&& val){
	T t = val;
	cout << is_reference<T>::value << endl;
	cout << typeid(decltype(val)).name() << endl;
}

void f(int v1, int& v2){
	cout << is_reference<decltype(v2)>::value << endl;
}

void g(int&& i, int& j){
	cout << is_reference<decltype(i)>::value << endl;
}

// 使用foward
template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2){
	f(forward<T2>(t2), forward<T1>(t1));
}


int main( ){
	//vector<int> vi = { 1,2,3,4,5 };
	//auto& i = fcn(vi.begin( ), vi.end( ));
	//i = 5;
	//cout << vi[ 0 ] << endl;
	//i = fcn(vi.begin( ), vi.end( ));
	////j = 6;
	//i = 7;
	//cout << vi[ 0 ] << endl;

	//f3(42);
	//int b = 5;
	////f3(static_cast<typename remove_reference<int>::type&&>(b));
	//f3(b);

	int j = 222;
	flip(g, j, 42);
	return 0;
}
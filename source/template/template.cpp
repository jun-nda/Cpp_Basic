#include <iostream>

using std::cout;
using std::endl;

// T的实际类型在编译时根据compare的使用情况来确定
template<typename T>
int compare(const T& v1, const T& v2){
	if( v1 < v2 ) return -1;
	if( v2 < v1 ) return 1;
	return 0;
}

// 类型参数（type parameter）也可以用来指定返回类型
template <typename T> T foo(T* p){
	T tmp = *p;
	//...
	return tmp;
}

// 错误：U之前必须加上class或typename，class好久没见到过了
//template<typename T, U>

// 非类型参数限制为以下几种，具体有什么用还需在项目里体会
// 1. 整形常量（包含枚举）
// 2. 指向objects/functions/members的指针
// 3. objects或者functions的左值引用，
// 4. std::nullptr_t
// 在模板定义内，模板非类型参数是一个常量值。在需要常量表达式的地方，可以使用非类型参数，例如，指定数组大小
template<unsigned N, unsigned M>
int compare(const char(&p1)[ N ], const char(&p2)[ M ]){
	int num[ N ];
	for( size_t i = 0; i < N; i++ )
	{
		num[ i ] = 5;
	}

	for( size_t i = 0; i < N; i++ )
	{
		cout << num[ i ] << endl;
	}
	return strcmp(p1, p2);
}

int main( ){
	cout << compare("h1i", "mom") << endl;
	return 0;
}
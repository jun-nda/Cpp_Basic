#include <iostream>

using std::cout;
using std::endl;

// T��ʵ�������ڱ���ʱ����compare��ʹ�������ȷ��
template<typename T>
int compare(const T& v1, const T& v2){
	if( v1 < v2 ) return -1;
	if( v2 < v1 ) return 1;
	return 0;
}

// ���Ͳ�����type parameter��Ҳ��������ָ����������
template <typename T> T foo(T* p){
	T tmp = *p;
	//...
	return tmp;
}

// ����U֮ǰ�������class��typename��class�þ�û��������
//template<typename T, U>

// �����Ͳ�������Ϊ���¼��֣�������ʲô�û�������Ŀ�����
// 1. ���γ���������ö�٣�
// 2. ָ��objects/functions/members��ָ��
// 3. objects����functions����ֵ���ã�
// 4. std::nullptr_t
// ��ģ�嶨���ڣ�ģ������Ͳ�����һ������ֵ������Ҫ�������ʽ�ĵط�������ʹ�÷����Ͳ��������磬ָ�������С
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
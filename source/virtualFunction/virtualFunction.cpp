#include <iostream>
// 内存对齐可以任意更改，但会造成内存读取次数变多
#pragma pack(1)
using std::cout;
using std::endl;

// https://blog.csdn.net/DRZ_2000/article/details/108799848 通过虚函数表调用虚函数
// https://zhuanlan.zhihu.com/p/30007037 内存对齐
// https://zhuanlan.zhihu.com/p/629281871 虚函数知识点汇总
class BaseMemberClass
{
public:
	BaseMemberClass( ) = default;
	~BaseMemberClass( ) = default;

private:

};

// 内存对齐指的一般是，一次内存分配中（大多数是分配一个对象或者一堆对象）的各个变量的内存对齐，所以一般只关注成员变量就好了
// 编译器会组织一次数据，使其尽可能
class BaseClass
{
public:
	BaseClass( ){
		x = rand();
	};
	~BaseClass( ) = default;

	// 把virtual去掉，class的大小就变成1了，加上virtual就变成8
	virtual void Print(){
		cout << "BaseClass Print" << endl;
	}

	virtual void Print2(int x){
		cout << "BaseClass Print2" << endl;
		cout << "this:         " << this << endl;
		cout << "x: " << x << endl;
		cout << "I can run with four legs" << endl;
	}

	void OverrideFunc( ){
		cout << "BaseClass OverrideFunc" << endl;
	}
private:
	//BaseMemberClass baseMember;
	int x;
	char y;
	//char y2;
};


class DerivedMemeberClass
{
public:
	DerivedMemeberClass( ) = default;
	~DerivedMemeberClass( ) = default;


private:

};


class DerivedClass : public BaseClass
{
public:
	DerivedClass( ) = default;
	~DerivedClass( ) = default;

	void Print( ) override { // override 防止自己不小心拼错
		cout << "DerivedClass Print" << endl;
	}

	void Print2(int x) override{
		cout << "DerivedClass Print2" << endl;
		cout << "this:         " << this << endl;
		cout << "x: " << x << endl;
	}

	void OverrideFunc( ){
		cout << "OverrideClass OverrideFunc" << endl;
	}

private:
	//DerivedMemeberClass derivedMember;
};

void output_raw_data(void *q, int n) {
	unsigned char *p = (unsigned char *)q;
	for (int i = 0; i < n; i++) {
		printf("%02x ", p[i]);  //不足2位的前面补0
	}
	printf("\n");
}
typedef void (* func)();
//typedef void (* func2)(int);// 错误，成员函数有隐式this参数
typedef void (* func2)(void*, int);
int main( ){
	BaseClass* derived = new DerivedClass( );

	uintptr_t* vptr = (uintptr_t*)derived;

	BaseClass* derived2 = new DerivedClass( );
	uintptr_t* vptr2 = (uintptr_t*)derived2;

	output_raw_data(derived, sizeof(BaseClass));
	output_raw_data(derived2, sizeof(BaseClass));

	BaseClass deruved3;
	output_raw_data(&deruved3, sizeof(BaseClass));

	//cout << "sizeof(derived2): " << sizeof(*derived2) << endl;
	//cout << "sizeof(deruved3): " << sizeof(deruved3) << endl;
	//cout << "sizeof(DerivedClass): " << sizeof(DerivedClass) << endl;

	// 这样输出是大端模式的16进制
	//cout << std::hex << *vptr << endl;
	//cout << std::hex << *vptr2 << endl;
	cout << std::hex << derived << endl;
	cout << std::hex << derived2 << endl;

	// 只要指针带有类型，它就可以使用数组下标，根据类型的单个对象的大小来遍历
	// ((func **)(derived2))[0][0]();
	//((func2 **)(derived2))[0][1](derived2, 145);

	// 这种多个指针符号，用数组来理解呢？ 每次解引用都会降低一层数组，到最后就没办法使用数组下标了
	// 解一次的结果是，虚表首地址，再数组下标一次，就是函数地址
	// 目前来说只能倒推出来类型，没有太好的方式
	func** vtable = (func**)derived2;
	(*vtable)[0]();
	(*((func **)(derived2)))[1]();

	func** vtable2 = (func**)&deruved3;
	(*vtable2)[0]();
	(*((func **)(&deruved3)))[1]();

	derived->OverrideFunc( );

	delete derived;

	return 0;
}



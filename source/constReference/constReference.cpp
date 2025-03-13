#include <iostream>

using std::cout;
using std::endl;

// member class 作为base class的成员，必须在前面定义，因为base构造时需要为其分配内存，无法使用前置声明
class BaseMemberClass
{
public:
	BaseMemberClass( );
	~BaseMemberClass( );

private:

};

BaseMemberClass::BaseMemberClass( )
{
	cout << "BaseMemberClass Constructor" << endl;
}

BaseMemberClass::~BaseMemberClass( )
{
	cout << "BaseMemberClass Destructor" << endl;
}

class BaseClass
{
public:
	BaseClass( );
	~BaseClass( );

	//BaseClass()

	int x;
private:
	BaseMemberClass baseMember;
};

BaseClass::BaseClass( )
{
	cout << "BaseClass Constructor" << endl;
}

BaseClass::~BaseClass( )
{
	cout << "BaseClass Destructor" << endl;
}


class DerivedMemeberClass
{
public:
	DerivedMemeberClass( );
	~DerivedMemeberClass( );

	void Print( ){
		cout << "DerivedMemeberClass Print" << endl;
	}
private:

};

DerivedMemeberClass::DerivedMemeberClass( )
{
	cout << "DerivedMemeberClass Constructor" << endl;
}

DerivedMemeberClass::~DerivedMemeberClass( )
{
	cout << "DerivedMemeberClass Destructor" << endl;
}


class DerivedClass : public BaseClass
{
public:
	DerivedClass( );
	~DerivedClass( );

private:
	DerivedMemeberClass derivedMember;
};

DerivedClass::DerivedClass( )
{
	cout << "DerivedClass Constructor" << endl;
	derivedMember.Print( );
}

DerivedClass::~DerivedClass( )
{
	cout << "DerivedClass Destructor" << endl;
}

void TestConstReference( const BaseClass& param){
	//param.x = 1; // 错误 const对象不可修改
}


int main( ){
	DerivedClass* derived = new DerivedClass( );
	delete derived;

	return 0;
}
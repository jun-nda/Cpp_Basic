#include <iostream>

using std::cout;
using std::endl;

// member class ��Ϊbase class�ĳ�Ա��������ǰ�涨�壬��Ϊbase����ʱ��ҪΪ������ڴ棬�޷�ʹ��ǰ������
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
	//param.x = 1; // ���� const���󲻿��޸�
}


int main( ){
	DerivedClass* derived = new DerivedClass( );
	delete derived;

	return 0;
}
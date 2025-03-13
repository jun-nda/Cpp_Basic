#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
/// <summary>
/// debugģʽ�£��������Զ����ɵĺ�������Ϊ��֪����ԭ��ᵼ������ʱ���ʧ��
/// ��ȥ�ԭ����֮����ʾ�����ľ�����ʾ������
/// </summary>
class BaseMemberClass
{
public:
	BaseMemberClass( ) = default;
	~BaseMemberClass( ) = default;
};

class BaseClass
{
public:
	BaseClass( ) = default;
	~BaseClass( ) = default;

private:
	BaseMemberClass baseMember;
};


class DerivedMemeberClass
{
public:
	DerivedMemeberClass( ) = default;
	~DerivedMemeberClass( ) = default;

private:
	vector<int> _vector;
};


class DerivedClass : public BaseClass
{
public:
	DerivedClass( ) = default;
	~DerivedClass( ) = default;

	DerivedClass(const DerivedClass&){
		cout << "DerivedClass Copy Constructor" << endl;
	}

	void Print( ){
		cout << "DerivedClass Print" << endl;
	}
private:
	DerivedMemeberClass derivedMember;
};


int main( ){
	DerivedClass derived;
	//derived.Print( );
	DerivedClass d2(derived);

	return 0;
}
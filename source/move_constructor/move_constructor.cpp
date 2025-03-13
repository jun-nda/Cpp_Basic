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

	//DerivedClass(DerivedClass&& der){
	//	cout << "DerivedClass Move Constructor" << endl;
	//}
	 
	void Print( ) const{
		cout << "DerivedClass Print" << endl;
	}
private:
	DerivedMemeberClass derivedMember;
};


void lVaulueFunction(const DerivedClass& lValue){
	/*cout << lValue << endl;*/
	lValue.Print( );
}

//void rVaulueFunction(int&& rValue){
//	cout << rValue << endl;
//}

int main( ){
	DerivedClass derived;
	//derived.Print( );
	DerivedClass d2(derived);
	lVaulueFunction(std::move(d2));

	// ��������Ч��Ŷ������std::moveһ�㶼�Ƿ��ڱ��ʽ����
	DerivedClass&& rvalue = std::move(d2);
	DerivedClass d3 = rvalue;
	// ��ȷ
	DerivedClass d4 = std::move(d2);

	return 0;
}
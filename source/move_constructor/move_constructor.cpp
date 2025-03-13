#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
/// <summary>
/// debug模式下，编译器自动生成的函数，因为不知名的原因会导致运行时检查失败
/// 不去深究原因，总之该显示声明的尽量显示声明。
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

	// 这样是无效的哦，所以std::move一般都是放在表达式里用
	DerivedClass&& rvalue = std::move(d2);
	DerivedClass d3 = rvalue;
	// 正确
	DerivedClass d4 = std::move(d2);

	return 0;
}
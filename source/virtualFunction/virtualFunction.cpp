#include <iostream>
// �ڴ�������������ģ���������ڴ��ȡ�������
#pragma pack(1)
using std::cout;
using std::endl;

// https://blog.csdn.net/DRZ_2000/article/details/108799848 ͨ���麯��������麯��
// https://zhuanlan.zhihu.com/p/30007037 �ڴ����
// https://zhuanlan.zhihu.com/p/629281871 �麯��֪ʶ�����
class BaseMemberClass
{
public:
	BaseMemberClass( ) = default;
	~BaseMemberClass( ) = default;

private:

};

// �ڴ����ָ��һ���ǣ�һ���ڴ�����У�������Ƿ���һ���������һ�Ѷ��󣩵ĸ����������ڴ���룬����һ��ֻ��ע��Ա�����ͺ���
// ����������֯һ�����ݣ�ʹ�価����
class BaseClass
{
public:
	BaseClass( ){
		x = rand();
	};
	~BaseClass( ) = default;

	// ��virtualȥ����class�Ĵ�С�ͱ��1�ˣ�����virtual�ͱ��8
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

	void Print( ) override { // override ��ֹ�Լ���С��ƴ��
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
		printf("%02x ", p[i]);  //����2λ��ǰ�油0
	}
	printf("\n");
}
typedef void (* func)();
//typedef void (* func2)(int);// ���󣬳�Ա��������ʽthis����
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

	// ��������Ǵ��ģʽ��16����
	//cout << std::hex << *vptr << endl;
	//cout << std::hex << *vptr2 << endl;
	cout << std::hex << derived << endl;
	cout << std::hex << derived2 << endl;

	// ֻҪָ��������ͣ����Ϳ���ʹ�������±꣬�������͵ĵ�������Ĵ�С������
	// ((func **)(derived2))[0][0]();
	//((func2 **)(derived2))[0][1](derived2, 145);

	// ���ֶ��ָ����ţ�������������أ� ÿ�ν����ö��ή��һ�����飬������û�취ʹ�������±���
	// ��һ�εĽ���ǣ�����׵�ַ���������±�һ�Σ����Ǻ�����ַ
	// Ŀǰ��˵ֻ�ܵ��Ƴ������ͣ�û��̫�õķ�ʽ
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



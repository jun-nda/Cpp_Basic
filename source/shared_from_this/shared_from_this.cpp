#include <iostream>
#include <memory>

using std::shared_ptr;
using std::enable_shared_from_this;
using std::make_shared;

class TestFromThis : public enable_shared_from_this<TestFromThis>{
public:
	TestFromThis( )
	{
		a = new int(2);
	}

	void Func( )
	{
		//auto ptr = shared_ptr<TestFromThis>(this);
		auto ppr = shared_from_this( );
		auto ptr = shared_ptr<TestFromThis>(ppr);
		
	}

	~TestFromThis( )
	{
		delete(a);
	}

private:
	int* a;
};


int main( )
{
	//TestFromThis* test = new TestFromThis( );
	shared_ptr<TestFromThis> testPtr(make_shared<TestFromThis>());
	testPtr->Func( );
}
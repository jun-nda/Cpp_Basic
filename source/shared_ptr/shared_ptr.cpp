#include <iostream>

using std::cout;
using std::endl;

//template < typename T >
class SharedPtr{
public:
	SharedPtr(int* ptr = nullptr) : _ptr(ptr)
	{
		count = new int(1);
	};

	SharedPtr(const SharedPtr& sharedPtr){
		this->_ptr = sharedPtr._ptr;
		this->count = sharedPtr.count;
		(*this->count)++;
	}

	SharedPtr(SharedPtr&& sharedPtr)
	{
		this->_ptr = sharedPtr._ptr;
		sharedPtr._ptr = nullptr;
		this->count = sharedPtr.count;
		sharedPtr.count = nullptr;
	};

	SharedPtr& operator = (const SharedPtr& sharedPtr )
	{
		if( this->_ptr != nullptr ){
			(*count)--;
		}
		this->_ptr = sharedPtr._ptr;
		this->count = sharedPtr.count;
		(*this->count)++;

		return *this;
	}

	//SharedPtr& operator = (SharedPtr&& sharedPtr )
	//{

	//}

	~SharedPtr( ){
		if( count != nullptr ){
			(*count)--;
			if( (*count) <= 0 ){
				delete _ptr;
				cout << "Îö¹¹" << endl;
			}
		}
	}

public:
	int* _ptr;
	int* count;
};

int main( ){
	int* num = new int(6);
	int* numb = new int(7);

	SharedPtr a(num);

	//SharedPtr b(numb);
	SharedPtr b(std::move(a));

	//b = a;
	
	return 0;
}
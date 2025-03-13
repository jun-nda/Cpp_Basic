#include <iostream>
#include <type_traits>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::remove_reference;
using std::is_reference;


int main( ){    
	const int i = 0;
	auto& ci = i;
	//ci = 1;
	std::cout << "ci is const: " << std::is_const<std::remove_reference<decltype(ci)>::type>::value << std::endl;
	//std::cout << "ci is reference: " <<  << std::endl;

	//const auto f = ci;

	//auto *n = &ci, *p2 = &ci;
	auto cs = &ci;
	//int& i2 = i;
	decltype(ci) y = i;
	//cout << "Type of y: " << typeid(f).before(typeid(f)) << endl;
	return 0;
}
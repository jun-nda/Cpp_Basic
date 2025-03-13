#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool isShorter(const string& s1, const string& s2){
	return s1.size( ) < s2.size( );
}

bool isBigger(const string& a, size_t sz){
	return a.size( ) >= sz;
}

int main( ){
	vector<string> strs = { "fox", "jumps", "over", "quick", "red", "slow", "the", "turtle" };

	//std::find(strs.begin( ), strs.end( ), "2");
	std::sort(strs.begin( ), strs.end( ), isShorter);
	//std::find_if(strs.begin( ), strs.end( ), isBigger);
	int sz = 2;
	std::find_if(strs.begin( ), strs.end( ), 
		[sz](const string& a){ return a.size( ) >= sz; });

	auto f = []{ return 42; };
	cout << f( ) << endl;

	return 0;
}
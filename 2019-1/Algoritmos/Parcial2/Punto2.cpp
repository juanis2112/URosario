#include <iostream>
#include <set>
using namespace std;

template<typename datatype>
bool subset(set<datatype> & a, set<datatype> & b) {
	for (auto iter = a.begin(); iter != a.end(); ++iter) {
		if (!b.count(*iter))
			return false;
	}
	return true;
}

int main() {
	set<int> a = {3, 4};
	set<int> b = {6, 7};
	set<int> c = {1, 2, 3, 4, 5};
	if (subset(a, c))
		cout << "A esta contenido en C" << endl;
	else 
		cout << "A no esta contenido en C" << endl;
	if (subset(b, c))
		cout << "B esta contenido en C" << endl;
	else
		cout << "B no esta contenido en C" << endl;
	return 0;
}
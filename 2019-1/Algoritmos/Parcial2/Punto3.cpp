#include <iostream>
using namespace std;

void to_binary(const int * const n);
void to_binary_helper(const int * const n);

int main() {
    for (int i = -9; i < 10; i++)
        to_binary(&i);
	return 0;
}

void to_binary(const int * const n) {
	to_binary_helper(n);
	cout << endl;
}

void to_binary_helper(const int * const n){
	if (*n >= 0) {
		if (*n != 0 && *n != 1) {
			const int temp = *n/2;
			const int *temp_2 = &temp;
			to_binary_helper(temp_2);
			cout << (*n)%2;
		}
		else {
			cout << *n;
		}
	}
	else {
		cout << '-';
		const int temp = -1*(*n);
		const int *temp_2 = &temp;
		to_binary_helper(temp_2);
	}
}
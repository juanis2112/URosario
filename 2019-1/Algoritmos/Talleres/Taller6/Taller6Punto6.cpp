#include <iostream>
#include <queue>
using namespace std;

const char enter = '\n';
const char salto = '*';

void wait(void);
queue<char> store(void);
void retrieve(queue<char> & kb);
int main(void) {
	queue<char> keybuff;
	keybuff = store();
	retrieve(keybuff);
	return 0;
}
void wait(void) {
	for (int i = 0; i < 5e7; i++) {}
}
queue<char> store(void) {
	char c;
	queue<char> message;
	while (c != enter) {
		c = getchar();
		message.push(c);
	}
	return message;
}
void retrieve(queue<char> & structure) {
	char ch;
	cout << "The message you entered is:\n\n";
	while (!(structure.empty())) {
		if (structure.front() != salto) {
			cout << structure.front() << flush;
			wait();
			structure.pop();
		}
		else {
			cout << endl << flush;
			wait();
			structure.pop();
		}
	}
}

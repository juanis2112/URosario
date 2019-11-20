#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string, string> doMap(string name);

int main() {
	auto mp = doMap("Punto1");
	cout << "Exit Code" << "\t" << mp.at("Exit Code") << endl;
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		if (iter->first != "Exit Code")
			cout << iter->first << "\t" << iter->second << endl;
	}
	return 0;
}

map<string, string> doMap(string name) {
	map<string, string> out;
	fstream archivo(name+".txt");
	string linea, temp;
	int count = 0;
	if (!archivo.is_open()) {
		archivo.open(name+".txt", ios::in);
	}
	while(getline(archivo, linea)) {
		pair<string, string> pr;
		for (size_t i = 0; i < linea.size(); ++i) {
			char t = linea.at(i);
			if (t != '\t' && count%4 < 2) {
				temp.push_back(t);
			}
			else if (t == '\t' && count%4 < 2) {
				if(count%4 == 0){
					pr.first = temp;
				}
				else if (count%4 == 1){
					pr.second = temp;
				}
				count++;
				temp = "";
			}
			else {
				count = 0;
				out.insert(pr);
				break;
			}
		}
	}
	return out;
}

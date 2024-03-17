#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
int findletter(string inputstr, char letter) {
	int flag = 0;
	for (int j = 0; j < inputstr.size(); j++) {
		if (inputstr[j] == letter) {
			flag = 1;
			return j;
		}
	}
	return string::npos;
}
int main() {
	string inputstr;
	cin >> inputstr;
	char vowels[10] = {'a','e','i','o','u','y'};
	for (int i = 0; i < 10; i++) {
		if (findletter(inputstr,vowels[i]) != string::npos) {
			cout << vowels[i];
		}
	}
}

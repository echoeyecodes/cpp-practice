#include <iostream>
#include <vector>
#include <string>

using namespace std;

//creates a copy of the character array passed at a new memory address, while retaining the former;

char* copyString(char* str, int size) {
	char* x = new char[size];
	for (int i = 0; i < size; i++) {
		x[i] = str[i];
	}
	return x;
}


int main() {

	char values[] = "Dude";

	auto v = copyString(values, sizeof(values)/sizeof(values[0]));

	cout << v << endl;
	return 0;

}

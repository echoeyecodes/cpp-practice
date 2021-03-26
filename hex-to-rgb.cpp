#include <iostream>
#include <string>

using namespace std;

int getHexValue(char value) {
	switch (value){
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
		case 'F':
		return 15;
	default:
		return value - '0';
	}
}


int hexToDecimal(string* str) {

	int acc = 0;
	signed int size = str->size() - 1;

	while (size >= 0) {
		for (auto ii : *str) {
			acc += (int) (getHexValue(toupper(ii)) * pow(16, size));
			--size;
		}
	}
	return acc;
}

string hexToRGB(string* value) {
	static int RED = 0xFF0000;
	static int GREEN = 0x00FF00;
	static int BLUE = 0x0000FF;
	string result;

	auto r = (hexToDecimal(value) & RED) >> 16;
	auto g = (hexToDecimal(value) & GREEN) >> 8;
	auto b = (hexToDecimal(value) & BLUE);

	return result.append(to_string(r)).append(",").append(to_string(g)).append(",").append(to_string(b));
}


int main() {

	string hexValue = "886fa3";

	cout << hexToRGB(&hexValue) << endl;
	return 0;

}

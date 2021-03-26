#include <iostream>
#include <string>

using namespace std;

string parseHexValue(int value) {
	switch (value) {
	case 10:
		return "A";
	case 11:
		return "B";
	case 12:
		return "C";
	case 13:
		return "D";
	case 14:
		return "E";
	case 15:
		return "F";
	default:
		return to_string(value);
	}
}

string decimalToHex(int v) {
	const int BASE = 16;
	int value = v;
	string acc("");

	//if initial value of v is 0, skip loop and attach 0 to accumulator
	if (value == 0) {
		acc.append("00");
	}
	else {
		while (value != 0) {
			int i = value / BASE;
			int modulo = value % BASE;
			acc.append(parseHexValue(abs(modulo)));
			value = i;
		}
	}

	acc.size() == 1 ? acc.append("0") : acc.append(""); //prefix string with 0 incase it is less than 10
	reverse(acc.begin(), acc.end());
	return acc;
}

string printHex(int r, int g, int b) {
	string result("#");

	result.append(decimalToHex(r)).append(decimalToHex(g)).append(decimalToHex(b));
	return result;
}

int main() {

	cout << printHex(0, 0, 0) << endl;

	return 0;

}

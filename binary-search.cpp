#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

	vector<int> scores = { 0,1,2,3,4,5,6 };

	auto find = 7;
	auto size = scores.size();
	auto begin = scores.begin();
	auto end = scores.end();
	auto mid = (end - begin) / 2;

	auto temp = begin + mid;

	while (temp != end && find != *temp) {
		if (find < *temp) {
			end = temp;
		}
		else {
			begin = temp+1;
		}
		temp = begin + ((end - begin)/2);
	}

	cout << (temp == end);

	return 0;

}

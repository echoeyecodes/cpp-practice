#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> scores = {1,1,1,2,5,5,5,1,1,1,2,2,5,5,5,9 };
	auto size = scores.size();

	int count = 0;

	while (count < size) {
		int index = count;
		for (auto i = count; i < size; i++) {
			if (scores[i] < scores[index]) {
				index = i;
			}
		}

		auto& begin = scores[count];
		auto& end = scores[index];
		
		auto temp = begin;

		begin = scores[index];
		end = temp;

		count++;
	}

	for (auto i : scores) {
		cout << i <<endl;
	}

	return 0;

}

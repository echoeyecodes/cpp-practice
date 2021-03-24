#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> scores = { 3,17,87,2,5,6,99 };
	bool swap = true;

	while (swap) {
		swap = false;
		auto begin = scores.begin();
		auto end = scores.end();

		while ((begin != end) && begin + 1 != end) {
			auto& now = *begin;
			auto& next = *(begin + 1);
			if (now > next) {
				auto current = now;
				now = next;
				next = current;
				swap = true;
				/*swap = true;*/
			}
			begin++;
		}
	}

	for (auto i : scores) {
		cout << i << endl;
	}

	return 0;

}

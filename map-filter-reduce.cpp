#include <iostream>
#include <vector>
#include <string>

using namespace std;


template<typename T>
void forEach(vector<T>& values, void(*function)(T)) {
	for (auto item : values) {
		function(item);
	}
};


template<typename T>
vector<T> map(vector<T>& values, T(*function)(T)) {
	vector<T> new_array = {};
	for (auto item : values) {
		auto newItem = function(item);
		new_array.push_back(newItem);
	}
	return new_array;
};


template<typename T>
vector<T> filter(vector<T>& values, bool(*function)(T)) {
	vector<T> new_array = {};
	for (auto item : values) {
		bool match = function(item);
		if (match) {
			new_array.push_back(item);
		}
	}
	return new_array;
};


template<typename T>
vector<T> flatMap(vector<vector<T>>& values, vector<T>(*function)(vector<T>)) {
	vector<T> new_array = {};
	for (auto item : values) {
		auto newItem = function(item);
		for (auto item1 : newItem) {
			new_array.push_back(item1);
		}
	}
	return new_array;
};

template<typename T, typename U>
U reduce(vector<T>& values, U(*function)(U, T, int), U init) {
	auto new_value = init;
	int count = 0;
	for (auto item : values) {
		new_value = function(new_value, item, count);
		count++;
	}
	return new_value;
};



void doForEach(int x) {
	cout << x << endl;
};

int doMap(int x) {
	return x;
};

vector<int> doFlatMap(vector<int> x) {
	return x;
};

bool doFilter(int x) {
	return x % 2 == 0;
};

int doReduce(int acc, string next, int index) {
	return acc + next.size();
};


int main() {

	vector<int> scores = { 0,1,2,3,4,5,6 };
	vector<vector<int>> scores1 = { {0,1}, {1,2,3,5,4}, {5} };
	vector<string> scores2 = { "A", "E", "I", "O", "U" };
	string s = "";

	auto d = reduce<string, int>(scores2, [](int acc, string next, int index) {
		return int(acc + next.size());
		}, 0);
		cout << d << endl;
	return 0;

}

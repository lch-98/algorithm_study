#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Person {
	string name;
	int value;
	int score;
	int risk;
	int cost;
};

bool compare(const Person& a, const Person& b) {
	if (a.value != b.value) return a.value > b.value;         
	if (a.cost != b.cost) return a.cost < b.cost;             
	return a.name < b.name;                                   
}

int main() {
	int N;
	cin >> N;

	vector<Person> score_arr;
	for (int i = 0; i < N; i++) {
		string name;
		int score, risk, cost;
		cin >> name >> score >> risk >> cost;
		int val = (int)(pow(score, 3) / (cost * (risk + 1)));
		score_arr.push_back({ name, val, score, risk, cost });
	}

	sort(score_arr.begin(), score_arr.end(), compare);
	cout << score_arr[1].name << '\n';
}

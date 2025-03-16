#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Room {
	int level_min;
	int level_max;
	vector<pair<int, string>> players;
};

int main() {
	int p, m;
	cin >> p >> m;

	vector<Room> rooms;

	for (int i = 0; i < p; i++)
	{
		int l;
		string n;
		cin >> l >> n;

		bool matched = false;
		// 
		for (auto& room : rooms) 
		{
			if (room.level_min <= l && l <= room.level_max && room.players.size() < m)
			{
				room.players.push_back({ l, n });
				matched = true;
				break;
			}
		}
		// 조건을 만족하지 않는다면 새로운 방을 만듦
		if (matched == false) 
		{
			Room new_room;
			new_room.level_min = l - 10;
			new_room.level_max = l + 10;
			new_room.players.push_back({ l, n });
			rooms.push_back(new_room);
		}
	}

	// 출력 부분
	for (auto& room : rooms) 
	{
		sort(room.players.begin(), room.players.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
			return a.second < b.second; // 이름 사전순 정렬
		});

		if (room.players.size() == m) {
			cout << "Started!\n";
		}
		else {
			cout << "Waiting!\n";
		}

		for (const auto& player : room.players) {
			cout << player.first << " " << player.second << "\n";
		}
	}

	return 0;
}

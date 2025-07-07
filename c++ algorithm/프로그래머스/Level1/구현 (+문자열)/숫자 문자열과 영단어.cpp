#include <string>
#include <unordered_map>
using namespace std;

int solution(string s) {
    unordered_map<string, string> num_map = {
        {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
        {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

    string result = "";
    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            result += s[i];
        } else {
            temp += s[i]; 
            if (num_map.find(temp) != num_map.end()) {
                result += num_map[temp];
                temp = "";
            }
        }
    }

    return stoi(result);
}

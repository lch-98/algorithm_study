#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector<long long> num_arr;
    string num = to_string(n);
    for (int i=0; i<num.size(); i++) {
        num_arr.push_back(stoi(num.substr(i, 1)));
    }
    sort(num_arr.rbegin(), num_arr.rend());
    string answer = "";
    for (int i=0; i< num_arr.size(); i++) {
        answer += to_string(num_arr[i]);
    }
    return stoll(answer);
}
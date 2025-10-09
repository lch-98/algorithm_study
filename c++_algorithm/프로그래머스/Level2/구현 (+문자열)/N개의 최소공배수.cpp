#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int &a, int &b) {
    return a > b;
}

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end(), compare);
    
    int max_num = arr[0];
    int i = 1;
    while(1) {
        int chk_lcm = max_num * i;
        
        bool chk_flag = true;
        for (int i=1; i<arr.size(); i++) {
            if(chk_lcm % arr[i] != 0) {
                chk_flag = false;
                break;
            }
        }
        if (chk_flag) {
            answer = chk_lcm;
            break;
        }
        i++;
    }
    return answer;
}
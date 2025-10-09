#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int max_choose;
    unordered_map<int,int> chk_duplicate;
    for (int i = 0; i < nums.size(); i++) {
        chk_duplicate[nums[i]]++;
        if (chk_duplicate[nums[i]] >= 1) continue;
    }

    if (chk_duplicate.size() >= nums.size()/2) answer = nums.size()/2;
    else if (chk_duplicate.size() < nums.size()/2) answer = chk_duplicate.size();
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> giveup_math1 = {1, 2, 3, 4, 5};
    vector<int> giveup_math2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> giveup_math3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int people1 = 0, people2 = 0, people3 = 0;
    vector<int> people_sum;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == giveup_math1[i % giveup_math1.size()]) people1++;
        if (answers[i] == giveup_math2[i % giveup_math2.size()]) people2++;
        if (answers[i] == giveup_math3[i % giveup_math3.size()]) people3++;
    }
    people_sum.push_back(people1);
    people_sum.push_back(people2);
    people_sum.push_back(people3);
    
    int max_sum = *max_element(people_sum.begin(), people_sum.end());
    
    for (int i=0; i<people_sum.size(); i++) {
        if (people_sum[i] == max_sum) answer.push_back(i+1);
    }

    return answer;
}
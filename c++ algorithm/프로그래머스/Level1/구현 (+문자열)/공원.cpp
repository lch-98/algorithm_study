//PCCE 기출문제
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sort(mats.rbegin(), mats.rend());
    for (int i=0; i<park.size(); i++) {
        for (int j=0; j<park[0].size(); j++) {
            if(park[i][j] == "-1") {
                
                for(int q=0; q<mats.size(); q++) {
                    bool flag = true;
                    for(int h=i; h<i + mats[q]; h++) {
                        for(int w=j; w<j + mats[q]; w++) {
                            if (h>=park.size() || w>=park[0].size()) {flag = false; break;}
                            if (park[h][w] != "-1") {flag = false; break;}
                        }
                    }
                    if(flag) {answer = max(answer, mats[q]); break;}
                }
                
                
            }
        }
    }
    
    
    return answer;
}
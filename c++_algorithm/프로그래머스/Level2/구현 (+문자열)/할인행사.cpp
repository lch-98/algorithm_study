#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // 회원을 대상으로 매일 한 가지 제품을 할인
    // 할인하는 제품은 하루에 하나씩만 구매 가능
    int max_day = 0;
    vector<pair<string,int>> want_number(want.size());
    for (int i=0; i< want.size(); i++) {
        want_number[i].first = want[i];
        want_number[i].second = number[i];
        max_day += number[i];
    }
    
    for (int i=0; i<=discount.size()-max_day; i++) {
        unordered_map<string, int> discount_chkday;
        for (int j=i; j<i+max_day; j++) {
            discount_chkday[discount[j]]++;
        }
        // 할인 확인 부분
        bool flag = true;
        for (int k=0; k<want.size(); k++) {
            if (want_number[k].second <= discount_chkday[want[k]]) continue;
            else {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}
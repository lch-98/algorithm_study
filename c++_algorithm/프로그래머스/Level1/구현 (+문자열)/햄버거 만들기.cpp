#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    // 1 = 빵, 2 = 야채, 3 = 고기
    // 빵 - 야채 - 고기 - 빵 1231
    string str_ingredient = "";
    for (int i=0; i<ingredient.size(); i++) {
        str_ingredient += to_string(ingredient[i]);
        if (str_ingredient.size() >= 4) {
            int len = str_ingredient.length();
            if (str_ingredient[len-4] == '1' && str_ingredient[len-3] == '2' && str_ingredient[len-2] == '3' && str_ingredient[len-1] == '1') {
                str_ingredient.erase(str_ingredient.end() - 4, str_ingredient.end());
                answer++;
            }
        }
    }
    return answer;
}
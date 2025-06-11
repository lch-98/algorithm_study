#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    string third = "";
    while (n > 0) {
        third = third + to_string(n % 3); // 앞뒤 반전(3진법)
        n /= 3;
    }
    const int len = third.length() - 1;
    for(int i=third.length()-1; i >= 0; i--) {
        answer += pow(3,len - i) * stoi(third.substr(i, 1));
    }
    return answer;
}
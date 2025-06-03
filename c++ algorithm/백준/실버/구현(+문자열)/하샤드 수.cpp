#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string str_x = to_string(x);
    
    int sum_ = 0;
    for(int i=0; i<str_x.length(); i++) {
        sum_ += stoi(str_x.substr(i,1));
    }
    answer = x % sum_ == 0 ? true : false;
    return answer;
}
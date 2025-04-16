#include <string>
#include <vector>
#include <stack>
using namespace std;

bool chk(string str) {
    stack<char> st;

    for (char ch : str) 
    {
        if (ch == '(' || ch == '[' || ch == '{') 
        {
            st.push(ch);
        } 
        else 
        {
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty(); // 모두 짝지어졌는지 확인
}

string cut(string s, int change_cnt) {
    string str = "";
    // 남은 길이만큼 자름
    for (int i=change_cnt; i<s.length(); i++) {
        str += s[i];
    }
    // 길이만큼 잘라서 뒤로 붙임
    for (int i=0; i<change_cnt; i++) {
        str += s.substr(i,1);
    }
    return str;
}

int solution(string s) {
    int answer = 0;

    for (int i=0; i<s.length(); i++) {
        if (chk(cut(s, i))) answer++;
    }

    return answer;
}
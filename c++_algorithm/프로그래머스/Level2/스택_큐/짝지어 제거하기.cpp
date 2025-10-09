#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); // 짝이 맞으면 제거
        } else {
            st.push(c); // 아니면 넣기
        }
    }
    return st.empty() ? 1 : 0;
}
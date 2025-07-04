#include <string>
#include <vector>

using namespace std;
// arr은 이진수로 만들어진 맵
string binary(int num, int arr_size) {
    string str;
    while(num > 0) {
        str = to_string(num%2) + str;
        num = num / 2;
    }
    // 남은 길이만큼 맨 앞에 '0'을 추가해줘야 함
    int len = str.length();
    if (len != arr_size) {
        for (int i=0; i < arr_size-len; i++) {
            str = '0' + str;    
        }
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    vector<string> arrString1;
    for (int i=0; i<arr1.size(); i++) {
        arrString1.push_back(binary(arr1[i], n));
    }
    
    vector<string> arrString2;
    for (int i=0; i<arr1.size(); i++) {
        arrString2.push_back(binary(arr2[i], n));
    }
    
    for (int i=0; i<n; i++) {
        string str = "";
        for (int j=0; j<n; j++) {
            if (arrString1[i][j] == '1' || arrString2[i][j] == '1') {
                str = str + '#';
            }
            else {
                str = str + ' ';
            }
        }
        answer[i] = str;
    }
    return answer;
}
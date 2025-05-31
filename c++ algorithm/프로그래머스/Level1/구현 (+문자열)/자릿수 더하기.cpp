#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    string copy_n = to_string(n);
    
    for(int i=0; i< copy_n.size(); i++) {
        answer += stoi(copy_n.substr(i,1));
    }
    
    return answer;
}

/*
#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n > 0) {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}
*/
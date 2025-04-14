#include <string>
#include <vector>
#include <iostream>
using namespace std;

int func_fibo(int prev, int next, int curr_depth, int target) {
    if (curr_depth == target) return (prev + next) % 1234567;
    return func_fibo(next, (prev + next) % 1234567, curr_depth + 1, target);
}

int solution(int n) {
    return func_fibo(0, 1, 2, n);
}
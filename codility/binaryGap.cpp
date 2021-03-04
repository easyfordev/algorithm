/* Codility - Lesson1. BinaryGap */
// you can use includes, for example:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    // 일단 이진수 만들기
    int num = N;
    string str = "";
    while(num != 1) {
        int mod = num%2;
        str = str + to_string(mod);
        num /= 2;
    }
    str = str + "1";

    string bin = str;
    reverse(bin.begin(), bin.end());
    // cout << bin;

    // 1의 위치 모두 저장
    vector<int> v;
    int len = bin.size();
    for(int i=0;i<len;i++) {
        if(bin[i] == '1') {
            v.push_back(i);
        }
    }

    // 위치들간의 차의 최댓값 구하기
    int ans = 0;
    len = v.size();
    for(int i=0;i<len-1;i++) {
        int temp = v[i+1] - v[i] -1;
        ans = max(ans, temp);
    }

    return ans;
}

int main(){
    printf("%d\n",solution(32)); // 1041->5리턴, 32 -> 0 리턴
    
}

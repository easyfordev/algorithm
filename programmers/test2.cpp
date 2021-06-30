/*
Programmers - 내적 구하기
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    // a와 b의 내적구하기
    // a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1]
    int len = a.size();

    for(int i=0;i<len;i++) {
        answer += a[i]*b[i];
    }
    return answer;
}

int main(){
    string s = "1";

    vector<int> a = {1,2,3,4};
    vector<int> b = {-3,-1,0,2};

    cout << solution(a,b);
}

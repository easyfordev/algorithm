/*
프로그래머스 - 보석 쇼핑
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {    
    vector<int> answer;
    int len = gems.size();

    // 지금까지 구매한 보석들을 저장하는 맵
    unordered_map<string, int> m; // 보석종류:갯수

    // Unique한 보석의 갯수 구하기
    set <string> gem_set(gems.begin(), gems.end());
    int u_len = gem_set.size();

    // 투포인터
    int left = 0;
    int right = 0;
    int ans = len; // 가장 짧은 구간의 길이(숫자 갯수). 초기값은 배열 전체 길이
    answer = {1, len};
    // (초기 값) 보석 구매
    m.insert(make_pair(gems[left], 1));
    // printf(">>>%d\n",u_len);

    while(right<len) {
        // 현재 상태가 정답인지(모든 보석을 갖고있는지) 검사
        int length = right-left; // 갯수

        if(m.size() == u_len ) {
            // 구간이 현재보다 짧으면, 정답 업데이트
            if(length < ans) {
                // 정답 업데이트
                ans = length;
                answer = {left+1,right+1};
            } 
            // left를 더 줄여서 구간을 더 줄여본다.
             // 현재 한개밖에 없으면 아얘 삭제
            if(m[gems[left]] == 1)  m.erase(gems[left]);
            // 아니면, 하나 빼기
            else  m[gems[left]]--;
            left++;
           
        } else { // 모든 보석을 갖고있지 않으면,
            right++; // 보석을 더 담는다.

            // (중요) 여기때문에 계속 틀렸던 것 같다. 종료 조건을 잡아준다.
            if (right == len)
                break;
                
            if(m.find(gems[right]) == m.end())  // 없을때는
                m.insert(make_pair(gems[right], 1));
            else // 이미 있을때는
                m[gems[right]]++;

        }
    }

    return answer;
}

int main(){
    vector<string> input = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<string> input2 = {"AA", "AB", "AC", "AA", "AC"};
    vector<string> input3 = {"XYZ", "XYZ", "XYZ"};
    vector<string> input4 = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
    vector<string> input5 = {"A","B","B","B","B","B","B","C","B","A"};

    vector<int> ans = solution(input5);

    printf("%d %d\n", ans[0], ans[1]);
}
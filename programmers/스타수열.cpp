/*
프로그래머스 - 스타 수열 (Level 3)
유형 : 딱히 없음. 그리디? ..
- 처음에 케이스 7개정도 시간초과났음 => 정렬 빼니까 통과. 정렬이 생각보다 오래걸리나봐..
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> a) {
    // 가장 길이가 긴 스타수열의 길이 리턴
    int answer = -1;
    // 1. 길이가 2 이상의 짝수
    int len = a.size();
    if(len< 2)    return 0;

    // 등장 횟수 세고, 내림차순으로 정렬
    map<int, int> map;
    for(int i=0;i<len;i++)
        map[a[i]]++;
    vector< pair<int, int> > v(map.begin(), map.end());
    // sort(v.begin(), v.end(), cmp);

    // 문제 조건대로 탐색. x[i] 와 x[i+1]을 함께 검사
    for(int i=0;i< v.size();i++) {
        // 지금 정답보다 적게 등장하면 검사할 필요 없음
        if(v[i].second <= answer)  continue;
        
        int key = v[i].first;
        int size = 0; // 이번 기준값으로 만들 수 있는 스타수열의 길이

        for(int j=0;j<a.size()-1;j++) {
            // 기준값이 하나라도 있는지 검사
            if(a[j] != key && a[j+1] != key)    continue;
            // 조건 3 
            if(a[j] == a[j+1])  continue;

            size++;
            j++; // 두개씩 건너뛰기
        }

        // 정답 업데이트
        answer = max(size, answer);
    }

    return answer*2;
}

int main(){
    vector<int> input = {0,3,3,0,7,2,0,2,2,0};

    cout << solution(input);
}
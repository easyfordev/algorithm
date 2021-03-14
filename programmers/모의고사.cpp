/* Programmers - 완전탐색 - 모의고사

더 나은 풀이)
    - <algorithm>의 max_element(v.begin(), v.end() ) 사용
    - 나머지 연산으로 인덱스 접근해서 바로 정답 채점
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 1,2,3번 수포자가 찍는 방식이 각각 정해져있을 때, 정답을 가장 많이 맞힌 사람이 누구인지 배열아 담아 리턴
// 가장 높은 점수를 받은 사람이 여럿일 경우 return하는 값을 오름차순 정렬
vector<int> solution(vector<int> answers) {
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    // 정답 채점하기
    int len = answers.size();

    vector<int> check(3);
    for(int i=0;i<len;i++) {
        if( arr1[i%arr1.size()] == answers[i])  check[0]++;
        if( arr2[i%arr2.size()] == answers[i])  check[1]++;
        if( arr3[i%arr3.size()] == answers[i])  check[2]++;
    }

    // 최댓값 구하기
    int maxV = *max_element(check.begin(), check.end());

    // 제일 많이 맞은 사람 정답에 넣기
    vector<int> answer;
    for(int i=0;i<3;i++) {
        if(check[i] == maxV)
            answer.push_back(i+1);
    }

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<int> test{1, 2, 3, 4, 5};
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }
    printf("%d", solution(test));
}
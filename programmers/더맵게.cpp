/* Programmers - 힙 - 더 맵게
힙 == 우선순위 큐. <queue>의 priority_queue

처음에 몇 개 케이스 실패 (signal: segmentation fault (core dumped)) - 이유 : 문제에 나와있는 예외처리를 안했었음
벡터로 큐 초기화 똑똑하게 : 
priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    // 일단 큐에 다 넣기
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0;i<scoville.size();i++) {
        q.push(scoville[i]);
    }

    // 스코빌 지수가 K이상이 될 때 까지 반복해서 섞음
    int score = 0;
    int answer = 0;

    while(true) {
        // 예외처리 : 모든 음식의 스코빌 지수를 K이상으로 만들 수 없는 경우에는 -1을 리턴
        if(q.size() == 1) { // 여기까지 왔는데
            if(q.top() >= K)    return answer;
            else    return -1;
        } else if (q.size() == 0) { // 여기 올 일은 없을 것 같고
            return -1;
        }

        // 모든 음식의 스코빌 지수가 K이상인지 검사
        if(q.top() >= K)
            break;
        
        // 제일 작은 2개 뽑기
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();

        // 새로운 점수 계산
        // 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두번째로 맵지 않은 음식의 스코빌 지수 * 2)
        score = a + (b *2);
        q.push(score);

        answer++;
    }

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<int> test{3, 9};
    // string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }

    printf("답 : %d\n", solution(test, 7) );
}
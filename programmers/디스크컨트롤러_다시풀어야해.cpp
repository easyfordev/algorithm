/* Programmers - 힙 - 디스크 컨트롤러

우선순위 큐 쓰는건 알겠는데, 시간 계산하는게 생각보다 어려워서 처음에 틀렸다.

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp { // 소요시간이 짧은거 먼저 나오게
    bool operator()(vector<int> &a, vector<int> &b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    // 정렬말고 pq로 하는거즤. 소요시간 짧은 순서로 들어가도록
    priority_queue<vector<int>, vector< vector<int> >, cmp> pq;
    // 일단 다 꺼내서 pq에 넣기
    for(int i=0;i<jobs.size();i++) {
        pq.push(jobs[i]); // 요청 시점, 소요시간
    }
    
    // 평균 Turnaround Time(요청 ~ 종료 시간) 계산
    int time = 0;
    int sum = 0;
    
    // 제일 처음꺼
    int s = pq.top()[0]; // 요청 시간
    int t = pq.top()[1]; // 소요 시간
    pq.pop();
    
    time = time + (s + t); // 현재 시간
    sum = time - s; // Turnaround time
    // printf("%d %d time : %d\n", s,t, time);

    // 나머지
    while(!pq.empty()) {
        s = pq.top()[0]; // 요청 시간
        t = pq.top()[1]; // 소요 시간
        pq.pop();

        // 지금까지 요청시간보다 늦으면, 더해주기
        if(s > time) {
            time += (s - time);
        }

        // printf("%d %d time : %d\n", s,t, time);

        time += (t);
        sum += (time - s);
    }

    int answer = sum / jobs.size();
    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<vector<int> > test{{0,3}, {1,9}, {2,6}};
    // string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }

    printf("답 : %d\n", solution(test) );
}
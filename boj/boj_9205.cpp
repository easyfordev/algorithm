/*
머리가 아득해지는군 ... ㅎㅎ 못풀겠다 혼자..
앜 지도에서 한칸씩 움직이는 문제가 아니라,
특정 정점끼리 움직이는 문제고, 한 정점의 좌표가 음수로 표현될 수 있다는거지

그리고 생각을 해봐, 50m에 맥주 1개를 마시는거면, 한 정점 -> 다음 정점으로 갈 때 1000m이내면 갈 수 있는거잖아 ! ! 

결국 단순한 DFS/BFS 문제임

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std; 

int tc, n;
vector< pair<int, int> > v;
bool check[102];

int distance(int a, int b) { // 정점 a와 b사이의 거리 구하기
    // 거리 = x좌표의 차이 + y좌표의 차이
    return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}

void bfs(int num){
    queue<int> q;
    // 시작점 방문
    check[num] = true;
    q.push(num);

    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front();
        q.pop();

        // 다음 정점 정하기
        for(int i=0;i<n+2;i++) {
            // 아직 방문 안했고, 거리가 1000m이내이면
            if(check[i] == false && distance(x, i) <= 1000) {
                check[i] = true;
                q.push(i);
            }
        }
    }
    
}

int main(void) {
   scanf("%d", &tc);

   while(tc--) {
       // 이번 TC를 위해 초기화
       v.clear();
       memset(check, false, sizeof(check));

       scanf("%d", &n); 

       for(int i=0;i<n+2;i++) { // 시작점, n개 편의점, 도착점
            int a, b;
            scanf("%d %d", &a, &b);
            v.push_back(make_pair(a,b));
       }

       // 시작점부터 bfs 돌기
       bfs(0);

       // 도착점을 잘 방문했으면, happy 출력
       if(check[n+1] == true) printf("happy\n");
       else printf("sad\n");
   }
    
}
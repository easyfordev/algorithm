/* 이 문제는 BFS로 풀어야해 ... 생각을 좀 해보고 풀자. 처음에 걍 DFS로 풀었더니 틀림 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int arr[101][101]; // 1~N번까지 있음
int check[101];
int cnt[101];

int n, m;

void bfs(int x) {
   queue<int> q;
   check[x] = 0;
   q.push(x);

   while(!q.empty()) {
       // 큐에서 하나 꺼내기
       int num = q.front();
       q.pop();

       // 인접해있는 아이들 중 다음 정점 구하기
       for(int i=1;i<=n;i++) {
            // 나와 연결되어있고, 아직 방문안했으면 다음으로 방문
            if(arr[num][i] == 1 && check[i] == -1) {
                check[i] = check[num] + 1;
                q.push(i);
            }
        }
   }
}

int main(void) {
    scanf("%d %d", &n, &m);

    for(int i=0;i<m;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    // 한명씩 dfs 돌면서 배열에 방문 순서 저장 .. bfs를 돌아야하나..?

    for(int i=1;i<=n;i++) {
        memset(check, -1, sizeof(check));
        bfs(i);

        // 이번 정점의 케빈 베이컨 수 구하기
        int sum = 0;
        for(int j=1;j<=n;j++) {
            if(check[j] != -1) {
                sum += check[j];
            }
        }

        cnt[i] = sum;
    }

    // 케빈 베이컨의 수가 가장 작은 사람 출력
    // 여러명일 경우 번호가 가장 작은 사람 출력
    int ans = cnt[1];
    int index = 1;
    for(int i=1;i<=n;i++) {
        if(cnt[i] < ans) {
            ans = cnt[i];
            index = i;
        }
    }

    printf("%d\n", index);

}
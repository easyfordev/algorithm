/*
16234. 인구 이동
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int n;

int L,R; // 기준값
int arr[51][51];
bool check[51][51];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool bfs(int a, int b){ // 시작점부터 연합 찾고 인구 바꾸기. 인구 이동이 발생 했는지 리턴
    queue< pair<int, int> > q;
    vector<pair<int, int > > v; // 인구이동이 발생한 점
    int sum = arr[a][b];

    // 시작점 초기화
    check[a][b] = true;
    q.push(make_pair(a, b));
    v.push_back(make_pair(a, b));

    // bfs 돌리기
    while(!q.empty()){
        // 큐에서 하나 빼기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 다음 방문할 정점 정하기
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 초과하면 방문 안함
            if(!(nx>=0 && nx<n && ny>=0 && ny<n)) continue;
            if(check[nx][ny] == true)   continue;
            // 두 나라의 인구차이가 L명 이상, R명 이하라면
            int diff = abs(arr[x][y] - arr[nx][ny]);

            if(L <= diff && diff <= R) {
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
                v.push_back(make_pair(nx, ny));
                sum += arr[nx][ny];
            }
        }
    }

    int len = v.size();
    if(len == 1) { // 인구이동할 인접한 국가가 없으면,
        return false;
    }
    // 평균 구해서 인구이동하기
    // 연합을 이루고있는 각 칸의 인구스 = (연합의 인구수) / 연합을 이루고있는 칸의 개수 (소수점 버림)
    int avg = sum / len;

    for(int i=0;i<len;i++){
        int x = v[i].first;
        int y = v[i].second;
        arr[x][y] = avg;
    }
    return true;
}

bool solution(){
    memset(check, false, sizeof(check));

    bool flag = false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            // 아직 방문 안했으면, 연합 찾기 시작
            if(check[i][j] == false && arr[i][j] > 0) {
                if(bfs(i, j))  flag = true;
            }
        }
    }

    // 한번이라도 인구이동이 발생했으면, true 리턴
    if(flag)    return true;
    else return false;
}

int main(){
    // 입력 받기
    scanf("%d %d %d", &n, &L, &R);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 인구 이동이 몇 번 발생하는지 구하는 프로그램
    int times = 0;
    while(true) {
        if(!solution()){ // 인구이동이 발생 안했으면 종료
            printf("%d\n", times);
            return 0;
        }
        times++;
    }
}


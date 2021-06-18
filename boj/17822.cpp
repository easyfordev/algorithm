/*
17822. 원판 돌리기 - 이제 풀기만 하면 된다
- 사람들은 한 줄씩 회전을 어떻게 할까? (시계는 그냥 하겠는데, 반시계는 위치를 빼야하니까 어려웠어)
- (틀렸습니다) 
    - 앜 진짜 사소한 조건 하나빼먹었다 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
    - 평균보다 큰 수는 -1, 작은수는 +1 할 때 이미 지워진 수인지 판단을 안했다. if(arr[][] != 1) 빼먹음  
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int arr[51][51]; // N은 1부터 쓰고(회전할 원판 배수 계산 떄문에), M은 0부터 쓰자
bool check[51][51]; // bfs용
int n, m, t;
int x, d, k; // 회전 연산

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print() {
    printf("==========\n");
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int calc(){ // 원판에 적힌 수의 합 구하기
    // 지워진 수 (-1) 은 꼭 제외하자
    int sum = 0;

    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++) 
            if(arr[i][j] != -1) sum += arr[i][j];
        
    return sum;
}

void modify(){  // 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
    // 평균 구하기
    int cnt = 0; // 진짜 숫자의 갯수
    int sum = 0;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] != -1) {
                cnt++;
                sum += arr[i][j];
            }
        }
    }

    // (중요한 예외처리) - Divide by zero 예외 처리
    if(cnt == 0)
        return;

    double avg = (double)sum / cnt;

    // 평균보다 큰 수는 -1, 작은수는 +1
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] != -1) {
                if((double)arr[i][j] < avg) {
                    arr[i][j]++;
                } else if((double)arr[i][j] > avg) {
                    arr[i][j]--;
                }
            }
            
        }
    }

}

void rotate(int num, int dir, int K) { // num번째 원판을 dir방향으로 K칸 회전
    int temp[51][51];
    memcpy(temp, arr, sizeof(arr));

    if(dir == 0){ // 시계
        for(int i=0;i<m;i++) {
            int pos = (i+K)%m;
            temp[num][pos] = arr[num][i];
        }
    } else if(dir == 1) { // 반시계
        for(int i=0;i<m;i++) {
            int pos = i-(K%m);
            if(pos<0)   pos = pos + m;
            temp[num][pos] = arr[num][i];
        }
    }

    memcpy(arr, temp, sizeof(temp));
}

bool bfs(int a, int b) { // 시작점
    // 시작점 초기화하기
    queue< pair<int, int> > q;
    vector< pair<int, int> > v; // 지울 수 좌표 저장
    check[a][b] = true;
    q.push(make_pair(a,b));
    v.push_back(make_pair(a,b));

    // bfs돌기
    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 새로 방문할 곳 정하기
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // (중요!) 이 문제의 특성상, 양쪽 y는 연결되어있다.
            if(ny == -1)    ny = m-1;
            if(ny == m) ny = 0;

            // 평소처럼 탐색
            // 범위 초과 안하고, 아직 방문 안했고, 진짜 숫자이면서, 숫자가 같으면
            if(nx >= 1 && nx <= n) {
                if(check[nx][ny] == false && arr[nx][ny] != -1) {
                    if(arr[x][y] == arr[nx][ny]) {
                        check[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                        v.push_back(make_pair(nx,ny));
                    }
                }
            }
        }
    }

    // 다 돌고나서, 지울 숫자가 있다면 지우기
    int s = v.size();
    if(s == 1) { // 나랑 같은애가 단 하나도 없다면
        return false;
    } else { // 같은애 있으면 지우기
        for(int i=0;i<s;i++) {
            int x = v[i].first;
            int y = v[i].second;

            arr[x][y] = -1;
        }

        return true;
    }

}

void solution(){
    // 1. 회전하기
    // 번호가 'x의 배수'인 원판을 d방향으로 k칸 회전
    for(int i=x;i<=n;i+=x) {
        rotate(i, d, k);
    }

    // 2. 인접한 수 찾고, 동시에 지우기
    memset(check, false, sizeof(check));

    // 원판에 수가 남아있으면, 인접하면서 수가 같은 것을 모두 찾는다.
    // 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
    bool flag = false;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            // 아직 방문하지 않았고, 진짜 숫자면 bfs 시작
            if(check[i][j] == false && arr[i][j] != -1) {
                bool result = bfs(i, j);
                if(result)  flag = true; // 한번이라도 지워진 적이 있다면, true로 바꾸기
            }
        }
    }

    // 3. 인접해서 지워진 수가 없는 경우, 숫자 보정
    if(!flag) { 
        modify();
    }
    // print();
}

int main(){
    // 입력 받기
    scanf("%d %d %d", &n, &m, &t);
    
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 연산 갯수만큼 반복
    for(int tc=0;tc<t;tc++) {
        scanf("%d %d %d", &x, &d, &k);
        solution();
    }

    // (결과) T번 회전 시킨 후 원판에 적힌 수의 합 구하기
    printf("%d\n", calc());
}


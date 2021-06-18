/*
20057. 마법사 상어와 파이어스톰
격자의 정확한 회전
얼음의 적절한 융해
가장 큰 덩어리 찾기
이 3가지 중에서는 아무래도 격자의 회전이 제일 난이도 있는 구현 파트이다. 격자의 시계/반시계 방향 회전은 자주 출제되는 유형이기 때문에 처음 코드를 짜보고 난 뒤에는 아예 그 코드를 외워두는게 낫다.

- 격자 나누고 반시계로 회전시키는게 제일 어려웠다.
    이 사람꺼 참고했다. (https://zoosso.tistory.com/73)
- (주의) 얼음 녹을 때, **동시에** 녹는다 !
    :  2중 for 문을 통해 순차적으로 바로바로 융해시켜주면 안되고, 어느 칸을 융해시킬 지 모든 칸에 대해 미리 정해놓은 다음 일괄적으로 융해시켜야 오류를 범하지 않는다. 
- 또 처음에 실수해서 TC 다틀렸다.
    - melt() 에서 영역 boundary 체크할 때 변수 실수함
    - bfs() 돌 때, 영역 유효한지 체크 안했음
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 65
using namespace std;

int n, Q;
int N; // 2^n
int arr[MAX][MAX], temp[MAX][MAX];
bool check[MAX][MAX]; // bfs용 방문 여부 검사 행렬

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print() {
    printf("============================\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void subRotate(int x, int y, int size){ // 격자 하나 안에서 회전시키기
    // 루프 돌면서 값 바꿔주기
    // printf("시작점 : (%d, %d) size-%d\n", x, y, size);

    // temp[i][j] 채우기
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            temp[j][size-1-i] = arr[i+x][j+y];
        }
    }

    // 다시 맵에 temp 복사
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            arr[i+x][j+y] = temp[i][j];
        }
    }
}

void rotate(int L) {
    // 1. 격자 쪼개서 회전시키기
    int size = pow(2, L);

    // 2^L * 2^L 격자의 시작점마다 반복
    for(int i=0;i<N;i+=size) {
        for(int j=0;j<N;j+=size) {
            subRotate(i, j, size);
        }
    }
}

void melt() { // 2. 얼음이 3개 이상 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
    vector<pair<int, int> > v; // 녹일 칸 좌표 저장

    // 모든 칸 탐색하기
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++){
            if(arr[i][j] == 0)  continue;

            int cnt = 0;

            // 인접한 영역 탐색
            for(int k=0;k<4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                // 범위 유효하고, 얼음이 있으면
                if(nx >=0 && nx <N && ny>=0 && ny<N) {
                    if(arr[nx][ny] > 0) cnt++;
                }
            }

            // 주위에 얼음이 3개 이상 인접해있지 않으면 얼음의 양이 1 줄어든다.
            if(cnt < 3) v.push_back(make_pair(i, j));
        }
    }

    // 녹일 칸 하나씩 녹이기
    for(int i=0;i<v.size();i++)
        arr[v[i].first][v[i].second]--;
}

int calc(){
    int sum = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j] > 0)
                sum += arr[i][j];
        }
    }
    return sum;
}

int bfs(int a, int b){ // 시작점
    int cnt = 0; // 이번에 방문한 정점 수 저장

    // 시작점 방문
    queue<pair<int, int> > q;
    check[a][b] = true;
    q.push(make_pair(a, b));
    cnt++;

    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 다음 방문할 정점 고르기
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 영역이 유효하고
            if(nx >=0 && nx <N && ny>=0 && ny<N) {
                // 얼음이 남아있고, 아직 방문 안했으면 방문하고 큐에 넣기
                if(arr[nx][ny] > 0 && check[nx][ny] == false) {
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main(){
    // 입력 받기
    scanf("%d %d", &n, &Q);
    N = pow(2, n);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 파이어스톰 총 Q번 시전
    while(Q--) {
        int L;
        scanf("%d", &L);
        
        rotate(L); // 1. 격자 쪼개서 회전시키기
        // print();

        melt(); // 2. 얼음 녹이기
        // print();
    }
   

    // 정답 구하기
    // 1. 남아있는 얼음의 합
    printf("%d\n", calc());
    
    // print();
    // 2. 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
    int ans = 0;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            // 얼음이 있고, 아직 방문 안했으면
            if(arr[i][j] > 0 && check[i][j] == false) {
                int temp = bfs(i, j); // bfs 시작
                ans = ans > temp ? ans : temp; // 정답 업데이트
            }
        }
    }

    printf("%d\n", ans);
}




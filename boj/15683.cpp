/*
15683. 감시
- 방향 여러개 잡는거 설계를 잘 해야 함
- 앜 진짜 실수 좀 그만해
    - 맨 처음에 cctv배열 입력받을 때 1~6조건 이렇게 줘서 틀렸었음 ㅠㅠ 번호는 5까지야아아아
*/
#include <iostream>
#include <vector>
using namespace std;

class CCTV{
public:
    int x, y, type;
    CCTV() {
        this->x = 0;
        this->y = 0;
        this->type = 0;
    }
    CCTV(int x, int y, int type) {
        this->x = x;
        this->y = y;
        this->type = type;
    }
};

int n, m;
int arr[9][9]; // 맵에서 0-빈칸, 6-벽, 1~5는 CCTV의 번호
int cctvDir[6] = {0,4,2,4,4,1}; // CCTV타입(1~5)별로 가능한 방향 경우의 수

vector<CCTV> cctvs; // cctv 배열
int ans = 100; // 사각지대의 최소 크기 출력

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int calc() { // 사각지대 갯수 세기
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0)  cnt++;
        }
    }
    return cnt;
}

void copyMap(int dest[9][9], int src[9][9]) {
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            dest[i][j] = src[i][j];
}

void watch(int x, int y, int dir) { // (x,y)를 dir방향으로 쭉 감시
    int nx = x;
    int ny = y;

    while(true) {
        nx += dx[dir];
        ny += dy[dir];

        // 범위 벗어나면 break
        if(!(nx >=0 && nx < n && ny>=0 && ny<m)) break;
        // 벽을 만나면 break
        if(arr[nx][ny] == 6)    break;
        // cctv는 그냥 값으로 덮어버려도 된다
        arr[nx][ny] = 7; // 검사했으면 7로 덮어준다
    }
}

void solve(int index){ // 검사할 인덱스
    // 정답을 찾은 경우
    if(index == cctvs.size()) {
        // 정답 업데이트
        int sum = calc();
        ans = sum < ans ? sum : ans;
        return;
    }

    // 불가능한 경우
    if(index > cctvs.size())    return;

    // 다음 경우
    // for문 돌면서 지금 index의 cctv에 따라 가능한 모든 경우의 수 탐색
    int type = cctvs[index].type;
    int x = cctvs[index].x;
    int y = cctvs[index].y;

    // 값 저장해두기
    int backup[9][9];
    int dir = 0;
    for(int i=0;i<cctvDir[type];i++) { // type에 따라 가능한 경우의 수 만큼 cctv로 탐색
        copyMap(backup, arr);

        if(type==1) {
            // cctv로 감시하면서 arr값 변경
            watch(x, y, (dir+i)%4);
        } else if(type == 2) {
            watch(x, y, (dir+i)%4);
            watch(x, y, (dir+i+2)%4);
        } else if(type == 3) {
            watch(x, y, (dir+i)%4);
            watch(x, y, (dir+i+1)%4);
        } else if(type == 4) {
            watch(x, y, (dir+i)%4);
            watch(x, y, (dir+i+1)%4);
            watch(x, y, (dir+i+2)%4);
        } else if(type == 5) {
            watch(x, y, (dir+i)%4);
            watch(x, y, (dir+i+1)%4);
            watch(x, y, (dir+i+2)%4);
            watch(x, y, (dir+i+3)%4);
        }

        // 다음 검사
        solve(index+1);
        // for문 안의 다른 경우를 위해 원복
        copyMap(arr, backup);
    }

}

int main(){
    // 입력받기
    scanf("%d %d",&n, &m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
            if(1 <= arr[i][j] && arr[i][j] <= 5) { // CCTV 배열에 넣기
                cctvs.push_back(CCTV(i, j, arr[i][j]));
            }
        }
    }

    // CCTV를 모든 경우의 수로 회전시키기
    solve(0);

    // 사각지대의 최소 크기 출력
    printf("%d\n", ans);
}

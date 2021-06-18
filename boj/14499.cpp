/*
14499. 주사위 굴리기
- 움직이는게, 정해진대로 움직이니까 겁먹지말고, 헷갈리지않게 차근차근 주사위 움직이는거 구현하기..
*/
#include <iostream>
using namespace std;
int n, m;
int k;

int x, y; // 주사위 위치
int arr[21][21]; // 맵

int moveDice[5][7] = { // [방향][그 방향으로 움직였을 때 육면체 각 위치의 번호]
    // moveDice[i][j] : i방향으로 이동했을 때, j번 위치에 원래 몇번 칸 값이 들어가는지
    {0,0,0,0,0,0,0}, // dummy
    {0, 4, 2, 1, 6, 5, 3}, // 동
    {0, 3, 2, 6, 1, 5, 4},// 서
    {0, 5, 1, 3, 4, 6, 2},// 북
    {0, 2, 6, 3, 4, 1, 5}// 남
};

int dice[7] = {0}; //주사위에 적혀있는 수(i번 위치의 주사위 값)

// 방향 (1-동, 2-서, 3-북, 4-남)
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void move(int d){ // 주사위를 d방향으로 굴린다
    int temp[7] = {0};

    for(int i=1;i<=6;i++)
        temp[i] = dice[moveDice[d][i]];
    
    // 다시 카피
    for(int i=1;i<=6;i++)
        dice[i] = temp[i];
}

bool solution(int d) { // 명령 이동 방향
    // 1. 주사위 굴리기
    int nx = x + dx[d];
    int ny = y + dy[d];

    // (종료 조건) 영역 밖이면 명령 무시
    if(!(nx>=0 && nx < n && ny>=0 && ny<m)) return false;

    move(d); // 주사위 굴리기
    // 주사위 위치 업데이트
    x = nx; y = ny;
    
    // 지도에 써있는 정수
    int num = arr[nx][ny];
    
    // 이동한 칸에 쓰여있는 수가 0이면,
    if(num == 0) {
        // 주사위의 바닥면에 쓰여있는 수가 칸에 복사
        arr[nx][ny] = dice[6];
    } else { // 0이 아니면
        // 칸에 쓰여있는 수가 주사위 바닥면으로 복사
        dice[6] = arr[nx][ny];
        // 칸에 쓰여있는 수는 0이 된다.
        arr[nx][ny] = 0;
    }

    return true;
}

int main(){
    // 입력받기
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int tc=0;tc<k;tc++) {
        int d;
        scanf("%d", &d);

        if(solution(d))
            printf("%d\n", dice[1]); // 윗면에 써있는 수 출력
    }
}
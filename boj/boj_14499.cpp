/* 
시뮬레이션
특별한 알고리즘이 전혀 안들어가고, 그냥 진짜 문제대로 차근차근 구현만 하면 된다.
헷갈리면 무조건 그림 그리기 !!
*/
#include <iostream>
using namespace std;

int n, m; // 지도 세로, 가로
int x, y; // 주사위 놓은 곳 좌표
int tc; // 명령의 개수

int dice[7] = {0}; // 1~6까지 주사위. 1이 윗면, 6이 아랫면, 사방 옆면 2(북)-> 4(서)-> 5(남)-> 3(동). 가장 처음엔 모든 면이 0
int arr[21][21];

// 동쪽 0, 서쪽 1, 북쪽 2, 남쪽 3
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void roll(int dir) {
    // 주사위 값 바꿀거니까, 현재 값 저장해주기
    int d1=dice[1], d2=dice[2], d3=dice[3], d4=dice[4], d5=dice[5], d6=dice[6];

    if(dir==0) { // 동쪽
        dice[1] = d4; // 위
        dice[6] = d3; // 아래 
        dice[4] = d6; // 옆(서)
        dice[3] = d1; // 옆(동)
    } else if(dir==1) { // 서쪽
        dice[1] = d3; // 위
        dice[6] = d4; // 아래 
        dice[4] = d1; // 옆(서)
        dice[3] = d6; // 옆(동)
    } else if(dir==2) { // 북쪽
        dice[1] = d5; // 위
        dice[6] = d2; // 아래 
        dice[5] = d6; // 옆(남)
        dice[2] = d1; // 옆(북)
    } else if(dir==3) { // 남쪽
        dice[1] = d2; // 위
        dice[6] = d5; // 아래 
        dice[5] = d1; // 옆(남)
        dice[2] = d6; // 옆(북)
    }
}

int main() {
    // 입력받기
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &tc);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 명령 입력 받기
    while(tc--) {
        int dir;
        scanf("%d", &dir); 
        dir--;

        // 주사위 위치 이동
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위 유효하지 않으면 넘어가기
        if(!(nx >=0 && nx < n && ny >=0 && ny < m)) continue;

        // 주사위 굴리기
        roll(dir);

        // 이동한 칸의 수가 0이면
        if(arr[nx][ny] == 0) {
            // 주사위의 바닥면에 쓰여있는 수가 칸에 복사된다
            arr[nx][ny] = dice[6];
        } else { // 0이 아닌 경우
            // 칸 => 주사위 바닥면 복사
            dice[6] = arr[nx][ny];
            // 칸은 0
            arr[nx][ny] = 0;
        }

        // 주사위 상단 값 출력
        printf("%d\n", dice[1]);

        // x와 y 값 바꾸기
        x = nx, y = ny;
    }
}
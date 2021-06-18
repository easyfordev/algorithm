/*
14891. 톱니바퀴
- 회전 구현을 머리를 잘 써서 해야 함.. (temp가 정석인듯)
*/
#include <iostream>
using namespace std;

int wheels[5][8]; // [톱니바퀴번호][8개톱니] , N극-0, S극-1
int k;

void rotate(int num, int dir) {
    int temp[8];
    if(dir == 1) { // 시계방향으로 회전
        for(int i=0;i<8;i++) {
            temp[(i+1)%8] = wheels[num][i];
        }
    } else if(dir == -1) { // 반시계
        temp[7] = wheels[num][0];
        for(int i=7;i>=1;i--) {
            temp[i-1] = wheels[num][i];
        }
    }

    // 카피
    for(int i=0;i<8;i++) {
        wheels[num][i] =  temp[i];
    }
    
}
void solution(int num, int dir) { // 회전시킨 톱니바퀴 번호, 방향(1: 시계, -1 : 반시계)
    int rotates[5] = {0}; // 0 - 회전 안함
    // 맨 처음 바퀴 회전
    rotates[num] = dir;

    // 1. 양쪽 검사하면서 회전방향 정해서 넣기
    // 걔 기준 오른쪽 쭉 검사
    int now = num;
    while(now <4) {
        // 내가 회전안했으면, 내 다음은 회전하지 않음
        if(rotates[now] == 0)   break;
        if(wheels[now][2] != wheels[now+1][6]) { // 극이 다르면 회전
            rotates[now+1] = rotates[now] * -1; // 나와 반대방향으로 회전
        } else { // 극이 같으면, 회전하지 않음
            rotates[now+1] = 0;
        }
        now++;
    }

    // 걔 기준 왼쪽 쭉 검사
    now = num;
    while(now > 1) {
        // 내가 회전안했으면, 내 다음은 회전하지 않음
        if(rotates[now] == 0)   break;

        if(wheels[now][6] != wheels[now-1][2]) { // 극이 다르면 회전
            rotates[now-1] = rotates[now] * -1; // 나와 반대방향으로 회전
        } else { // 극이 같으면, 회전하지 않음
            rotates[now-1] = 0;
        }
        now--;
    }

    // 2. 다같이 회전 방향에 따라 회전하기
    for(int i=1;i<=4;i++) {
        if(rotates[i] != 0)
            rotate(i, rotates[i]);
    }

}

int calc() { // 규칙에 따라 점수의 합 출력
    int sum = 0;
    if(wheels[1][0] == 1)   sum += 1;
    if(wheels[2][0] == 1)   sum += 2;
    if(wheels[3][0] == 1)   sum += 4;
    if(wheels[4][0] == 1)   sum += 8;

    return sum;
}

int main(){
    // 입력받기
    // 4개 톱니바퀴의 상태 (12시방향부터 시계방향)
    for(int i=1;i<=4;i++) {
        for(int j=0;j<8;j++) {
            scanf("%1d", &wheels[i][j]);
        }
    }

    // 회전 횟수
    scanf("%d", &k);

    for(int tc=0;tc<k;tc++) {
        int num, dir;
        scanf("%d %d", &num, &dir);
        
        solution(num, dir);
    }

    // 네 톱니바퀴 점수의 합 출력
    printf("%d\n", calc());
}
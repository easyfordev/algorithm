/*
17825. 주사위 윷놀이

Try and Error(이렇게 좀 그만 짜자)
- 다음칸 이동 로직이 틀렸음 (move, turn이 헷갈렸음)
- 이동하고 나서 위치 원복을 잘못했음
    - 꼭 origin 값 저장해주고, 잘 원복해주자!

- (틀렸습니다) 29%에서 틀렸음
    - turn 배열 값을 잘못넣었다 ㅠㅠ 위치로 넣어야하는데 score배열이랑 헷갈렸다.
    - 교훈 : 이런 기본 정보 setting할 때 집중해서 잘 보고 한번 더 확인하자!!
*/
#include <iostream>
using namespace std;

// 0번 ~ 32번
int map[33]; // map[i] : 내 다음으로 이동할 칸
int turn[33]; // turn[i] : 0이면 회전 안하는 칸, 번호가 있으면, 나 다음에 회전해서 가야할 칸
int score[33]; // score[i] : i번째 칸의 점수

int dice[10]; // 주사위 수

int piece[4]; // 4개 말의 현재 위치
bool check[33]; // check[i] : i번째 칸에 말이 있는지

int ans = -1; // 얻을 수 있는 점수의 최댓값

void solve(int index, int sum) { // 완전탐색 (주사위배열 인덱스, 지금까지 합)
    // 정답을 찾은 경우
    if(index == 10) {
        // 정답 업데이트
        ans = sum > ans ? sum : ans;
        return;
    }

    // 불가능한 경우
    if(index > 10) {
        return;
    }

    // 다음 경우
    // 말이 4개니까, 4개경우의 수 모두 탐방 
    for(int i=0;i<4;i++) {
        // (안되는 조건 1)도착 칸에 있으면 안함
        if(piece[i] == 21)  continue;
        
        // 이동하기
        int now = piece[i];
        int move = dice[index]; 
        int next = now;

        // 출발점이 회전해야하는 위치면, 회전하고 (회전하는 동시에 하나 움직였으므로 빼준다)
        if(turn[next] != 0) {
            next = turn[next];
            move--;
        } 
        // 쭉 이동할떄는 그냥 방향 따라감
        for(int j=0;j<move;j++) { // 주사위 수 만큼 한칸 씩 이동
            next = map[next];
        }

        // (안되는 조건 2) 이동을 마치는 칸에 다른 말이 있으면 고를 수 없음 (도착칸은 괜찮음)
        if(check[next] == true && next != 21) continue;

        // 이 말을 선택하고 옮기기
        check[now] = false;
        check[next] = true;
        
        piece[i] = next;

        // 다음 주사위로 넘어가기 (말이 이동을 마칠 때 마다 적혀있는 수가 점수에 추가된다.)
        solve(index+1, sum+score[next]);

        // for문안의 다른 경우를 위해 원복
        check[now] = true;
        check[next] = false;
        
        piece[i] = now;
    }
}

int main(){
    // 입력받기
    for(int i=0;i<10;i++) {
        scanf("%d", &dice[i]);
    }

    // 관리할 자료구조 초기화
    // 맵
    for(int i=0;i<=20;i++)  map[i] = i+1;
    map[21] = 21; // 도착칸 다음은 도착칸으로 넣어줘서 움직일 수 없게
    map[22]=23; map[23]=24; map[24]=25;
    map[25]=26; map[26]=27; map[27]=20;
    map[28]=29; map[29]=30; map[30]=25;
    map[31]=32; map[32]=25;

    // 회전하는 부분(경우의 수가 2개 있는 부분)
    turn[5]=22; turn[10]=31; turn[15]=28;

    // 점수
    score[0] = 0;
    for(int i=1;i<=20;i++)  score[i] = i*2;
    score[21] = 0;
    score[22]=13; score[23]=16; score[24]=19; score[25]=25;
    score[26]=30; score[27]=35; 
    score[28]=28; score[29]=27; score[30]=26;
    score[31]=22; score[32]=24;

    // 얻을 수 있는 점수의 최댓값 구하기(완전탐색)
    solve(0, 0);

    // 정답 출력
    printf("%d\n", ans);
}
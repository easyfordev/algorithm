/*
14888. 연산자 끼워넣기
*/
#include <iostream>
using namespace std;

int n;
int arr[12];
int ops[4]; // 각 연산마다 남은 갯수
int maxAns= (1000000000 + 1)*-1, minAns= 1000000000 + 1; // 

void solve(int index, int result) { // 검사할 인덱스, 지금까지의 연산 결과
    // 정답을 찾은 경우
    if(index == n) {
        // 정답 업데이트 
        maxAns = result > maxAns ? result : maxAns;
        minAns = result < minAns ? result : minAns;
        return;
    }

    // 불가능한 경우
    if(index>n) return;

    // 다음 경우
    // 연산자가 4개이기 때문에, 최대 총 4가지 경우의 수가 나온다.
    if(ops[0] > 0) { // 덧셈
        ops[0]--;
        solve(index+1, result + arr[index]);
        ops[0]++; // 다른 애들을 위해 원복
    }
    if(ops[1] > 0) { // 뺄셈
        ops[1]--;
        solve(index+1, result - arr[index]);
        ops[1]++; // 다른 애들을 위해 원복
    }
    if(ops[2] > 0) { // 곱셈
        ops[2]--;
        solve(index+1, result * arr[index]);
        ops[2]++; // 다른 애들을 위해 원복
    }
    if(ops[3] > 0) { // 나눗셈
        ops[3]--;
        solve(index+1, result / arr[index]);
        ops[3]++; // 다른 애들을 위해 원복
    }
    
}
int main(){
    // 입력 받기
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // +, -, *, / 의 개수
    for(int i=0;i<4;i++) {
        scanf("%d", &ops[i]);
    }

    solve(1, arr[0]); // 초기값 

    // (결과) 첫쨰줄에 최댓값, 둘째줄에 최솟값
    printf("%d\n%d\n", maxAns, minAns);
}

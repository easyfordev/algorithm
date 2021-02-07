/* 진짜 그냥 for문으로 푸는 Brute Force 문제
목표 채널 n이 최대 50만이므로, 0 ~ 100만(100만에서 채널을 줄이는게 더 빠를 수도 있으므로) 범위를 다 For문을 돌린다.

1. 이동할 채널 c(숫자)를 찾는다 (고장 안나서 거기로 이동할 수 있으면)
2. 거기를 기준으로 쭉 +를 누르거나, 쭉 -를 눌러서 n까지 이동한다. -> |c-n\
구한 값들 중 최솟값이 정답이다.
- 초기값 : 처음 채널인 100번에서 +,-만 이용해서 n번까지 이동할때 눌러야 하는 버튼 수 -> |100-n|
*/
#include <iostream>
#include <algorithm>
using namespace std; 
bool broken[10]; // 고장나면 true, 정상이면 false
int n, m;
int ans;

int possible(int x) { // x라는 채널을 숫자 버튼으로만 이동할 수 있는지 판단. 이동 못하면 0 리턴, 이동할 수 있으면 자릿수(눌러야하는 버튼 수) 리턴
    // 0번 채널이 목표일 경우 예외처리 (0은 모든 %해도 계속 0이므로)
    if(x == 0) {
        if(broken[0])   return 0;
        else    return 1;
    }
    
    int len = 0;
    while(x > 0) {
        int num = x % 10; 
        if(broken[num]) return 0;
        else {
            x /= 10;
            len++;
        }
    }
    return len;

}
int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0;i<m;i++) {
        int a;
        scanf("%d", &a);
        broken[a] = true;
    }

    // 초기 값 지정
    ans = abs(100 - n);

    // 0부터 쭉 다 모든 경우의 수 구하기
    for(int i=0;i<=1000000;i++) {
        int num = possible(i); // i라는 채널을 숫자로 몇번 눌러야 하는지

        if(num > 0) {
            int press = abs(i - n); // 그 채널에서 +나 -만 쭉 눌러서 n까지 이동
            ans = min(ans, press + num);
        }
    }

    printf("%d\n", ans);

}
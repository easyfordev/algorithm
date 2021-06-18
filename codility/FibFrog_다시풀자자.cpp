/* Codility - Fibonacci numbers - FibFrog
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 처음에 -1 위치에 있음 => 위치 N으로 가고싶음
// 한번에 F(K) 거리만큼 점프해서 움직일 수 있음
// A - 강 중간의 낙엽의 위치(0~N-1). N개의 정수
// A의 값은 0 or 1
// 목표 : -1에서 N까지 도달할 수 있는 최소 점프 횟수 계산
// 개구리는 -1 ~ N의 모든 위치를 점프할 수 있음
// 개구리가 강 반대편에 도달할 수 없으면 -1 리턴

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n+2);

    // 일단 1 ~ N+1까지의 피보나치 수 dp로 구하기
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; fibo.back() <= N + 1; ++i)
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
    
    // (중요!!!) 최솟값을 찾으려면 큰 값부터 점프를 해야하니까 뒤집어야 함
    reverse(fibo.begin(), fibo.end()); // <algorithm>


    for(int i=2;i<=n+1;i++) {
        dp[i] = dp[i-1] + dp[i-2];
        printf("%d ", dp[i]);
    }

    // fibo limit index 구하기
   
}

int main(){
    vector<int> test{0,0,0,1,1,0,1,0,0,0,0}; 
    printf("답 : %d\n", solution(test));
}
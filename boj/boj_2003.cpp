/* 투 포인터 */
#include <iostream>
using namespace std; 
int a[10000+1];

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    // 투포인터 알고리즘
    int lo=0, hi=0;
    int sum = 0;
    int ans = 0;

    while(lo <= hi && hi <= n) { // 종료조건 
        // 포인터 이동
        if(sum < m) {
            sum += a[hi++];
        } else if(sum >= m) { // 주의 : 합이 같을 경우도 감소시켜야해
            sum -= a[lo++];
        }

        // 정답 검사
        if(sum == m) ans++;
    }

    printf("%d\n", ans);

}
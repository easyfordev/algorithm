/* 런타임 에러 .. Out of bounds .. while문 종료조건에 left <= right 안넣었더니 그랬다 ... */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[100000+1];

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // 두 수의 차가 M이상이면서 제일 작은 경우
    // 가장 작은 차이 줄력
    sort(arr, arr+n);

    // 투 포인터 알고리즘
    int left=0, right = 0;
    int ans = 2000000000+1;
    // int sub = abs(arr[right]- arr[left]);

    while (right < n && left <= right) {  // left <= right 꼭 넣어야 함
        int temp = abs(arr[right]- arr[left]);

        // 정답 업데이트
        if(temp >= m && temp < ans) {
            ans = temp;
        }

        // 포인터 움직이기
        if(temp < m) {  // 차이가 M보다 작으면, 늘려야한다.
            right++;
        } else if(temp >= m) {
            left++;
        }

    }

    printf("%d\n", ans);
    
}
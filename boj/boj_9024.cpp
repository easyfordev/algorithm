#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--){
        int n, k;
        scanf("%d %d", &n, &k);

        vector<int> arr;
        arr.resize(n, 0);

        for(int i=0;i<n;i++) {
            scanf("%d", &arr[i]);
        }

        sort(arr.begin(), arr.end());
        // 투 포인터 알고리즘
        int left=0, right = n-1;
        int sum = arr[left] +  arr[right] ;
        int dist = abs(k - sum);
        int ans = 0;

        while(left < right) {
            int temp = arr[left] + arr[right];

            if(dist > abs(k-temp)) { // K와 더 가까우면, 정답 초기화
                dist = abs(k-temp);
                ans = 1;
            } else if( dist == abs(k-temp)) { // 기존 답과 거리가 같으면 경우의 수 하나 증가
                ans++;
            }

            // 포인터 이동
            if(temp >= k) { // K 보다 합이 더 크면, 줄여야 함
                right--;
            } else {
                left++;
            }
        }

        printf("%d\n", ans);

    }
    
}
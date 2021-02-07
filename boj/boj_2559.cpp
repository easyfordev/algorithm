#include <iostream>
using namespace std;

int n, k;
int arr[100000+1];

int main() {
    // 연속 며칠 동안 온도의 합이 가장 큰 값
    scanf("%d %d", &n, &k);
    
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    int ans = -99999999; // 처음에 초기값을 잘못줘서 틀렸네 .... ㅎㅎ 최댓값인데 arr[0]로 주면 안되지 ~!
    int sum = 0;
    int start = 0, end = 0;
    // 슬라이딩 윈도우
    for(int i=0;i<n;i++) {
        sum += arr[end];

        if(end >= k-1) { 
            if(sum > ans) { // 정답 업데이트
                ans = sum;
            }
            // 이동
            sum -= arr[start];
            start++;
        }
        end++;
    }
    printf("%d\n", ans);
}
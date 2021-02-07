#include <iostream>
#include <algorithm>
using namespace std; 
int arr[100000+1];

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // 투 포인터 알고리즘
    int left=0, right=0;
    int sum = 0;
    int len = 9999999;

    while(right <= n) {
        // 포인터 이동
        if(sum < s) {
            sum += arr[right++];
        } else if(sum >= s) {
            sum -= arr[left++];
        }

        // 정답 체크
        if(sum >= s) {
            len = min(len, right-left);
        }
    }

    // 합을 만드는 것이 불가능하면 0 출력
    if(len == 9999999)
        printf("0\n");
    else
        printf("%d\n", len);
    
}